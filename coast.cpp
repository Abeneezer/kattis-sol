#include <iostream>
#include <vector>

using namespace std;

class Coast {
   int n, m;
   vector<vector<int>> vmap;
   bool isLake = true;

   // Starts recursive methods
   void lakeCheckMain(int y, int x){
      vmap[y][x] = 10;
      if(vmap[y-1][x] == 0){
         lakeCheck(y-1, x);
      }
      if(vmap[y+1][x] == 0){
         lakeCheck(y+1, x);
      }
      if(vmap[y][x-1] == 0){
         lakeCheck(y, x-1);
      }
      if(vmap[y][x+1] == 0){
         lakeCheck(y, x+1);
      }

      if(isLake){
         lakeColor(y, x);
      }
      else{
         lakeDeColor(y, x);
      }
   }

   // Assign value 4 to all connected water
   void lakeColor(int y, int x){
      vmap[y][x] = 4;
      if(vmap[y-1][x] == 0 || vmap[y-1][x] == 10){
         lakeColor(y-1, x);
      }
      if(vmap[y+1][x] == 0 || vmap[y+1][x] == 10){
         lakeColor(y+1, x);
      }
      if(vmap[y][x-1] == 0 || vmap[y][x-1] == 10){
         lakeColor(y, x-1);
      }
      if(vmap[y][x+1] == 0 || vmap[y][x+1] == 10){
         lakeColor(y, x+1);
      }
   }

   // Assigns 0 to all checked water fields
   void lakeDeColor(int y, int x){
      //cout << "lets decolor" << endl;
      vmap[y][x] = 0;
      if(vmap[y-1][x] == 10){
         lakeDeColor(y-1, x);
      }
      if(vmap[y+1][x] == 10){
         lakeDeColor(y+1, x);
      }
      if(vmap[y][x-1] == 10){
         lakeDeColor(y, x-1);
      }
      if(vmap[y][x+1] == 10){
         lakeDeColor(y, x+1);
      }
   }

   // Checks neightboring fields for what and stops if edge is reached
   void lakeCheck(int y, int x){
      if((y < 1) || (x < 1) || (x > m) || (y > n) || !isLake){
         isLake = false;
      }
      else{
         //cout << y << x << " checking around me" << endl;
         if(vmap[y-1][x] == 0){
            vmap[y][x] = 10;
            lakeCheck(y-1, x);
         }
         if(vmap[y+1][x] == 0){
            vmap[y][x] = 10;
            lakeCheck(y+1, x);
         }
         if(vmap[y][x-1] == 0){
            vmap[y][x] = 10;
            lakeCheck(y, x-1);
         }
         if(vmap[y][x+1] == 0){
            vmap[y][x] = 10;
            lakeCheck(y, x+1);
         }
      }
   }


   public:
   int checker(){
      double result;
      cin >> n >> m;

      //Map init
      vmap.resize(n+2);
      for(int i = 0 ; i < n+2 ; ++i){
    	   vmap[i].resize(m+2);
      }

      // -1, m to 0
      // n, -1 to 0
      for (size_t i = 0; i <= m; i++) {
            vmap[0][i] = 0;
            vmap[n+1][i] = 0;
      }
      for (size_t i = 0; i <= n; i++) {
            vmap[i][0] = 0;
            vmap[i][m+1] = 0;
      }

      for (size_t i = 0; i < n; i++) {
         string tempStrng;
         cin >> tempStrng;
         for (size_t j = 0; j < m; j++) {
            int binVal = tempStrng.at(j) - 48;
            vmap[i+1][j+1] = binVal;
         }
      }

      // Sets all land fields to 4 as well as setting all inland lakes to the value 4
      for (size_t i = 1; i <= n; i++) {
         for (size_t q = 1; q <= m; q++) {
            if(vmap[i][q] == 1){
               vmap[i][q] = 4;
            }
            else if(vmap[i][q] == 0){
               isLake = true;
               //cout << i << ", " << q << " checking water" << endl;
               lakeCheckMain(i, q);
            }
         }
      }

      /*string resultStr;
      for (size_t i = 1; i < n+1; i++) {
         for (size_t q = 1; q < m+1; q++) {
            resultStr += to_string(vmap[i][q]);
         }
         resultStr += "\n";
      }
      cout << resultStr << endl;*/

      //Dynamically goes through the map from top left and looks left and above for other land
      //Skips water
      for (size_t i = 1; i <= n; i++) {
         for (size_t q = 1; q <= m; q++) {
            if(vmap[i][q] == 0){
               continue;
            }
            if(vmap[i-1][q] != 0){
               vmap[i][q] -= 1;
               vmap[i-1][q] -= 1;
            }
            if(vmap[i][q-1] != 0){
               vmap[i][q] -= 1;
               vmap[i][q-1] -= 1;
            }
         }
      }

      for (size_t i = 0; i <= n; i++) {
         for (size_t q = 0; q <= m; q++) {
            result += vmap[i][q];
         }
      }

      cout << result << endl;
   }
};



int main(){
   Coast c;
   c.checker();
}
