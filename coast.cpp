#include <iostream>
#include <vector>

using namespace std;

class Coast {
   int n, m;
   vector<vector<int>> vmap;
   bool isLake = true;

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
         //cout << y << x << " was lake, starting coloring" << endl;
         lakeColor(y, x);
      }
      else{
         vmap[y][x] = 0;
         //cout << y << x << " was not lake" << endl;
      }
   }

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
      if(!isLake){
         vmap[y][x] = 0;
      }
   }


   public:
   int checker(){
      double result;
      cin >> n >> m;

      //Map init
      vmap.resize(m+2);
      for(int i = 0 ; i < m+2 ; ++i){
    	    vmap[i].resize(n+2);
      }

      for (size_t i = 1; i <= n; i++) {
         for (size_t q = 1; q <= m; q++) {
            cin >> vmap[i][q];
         }
      }

      // -1, m to 0
      // n, -1 to 0
      for (size_t i = 0; i <= m; i++) {
            vmap[0][i] = 0;
            vmap[n+1][i] = 0;
            vmap[i][0] = 0;
            vmap[i][m+1] = 0;
      }

      for (size_t i = 1; i <= n; i++) {
         for (size_t q = 1; q <= m; q++) {
            if(vmap[i][q] == 1){
               vmap[i][q] = 4;
            }
            else if(vmap[i][q] == 0){
               isLake = true;
               lakeCheckMain(i, q);
            }
         }
      }

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

      /*string resultStr;
      for (size_t i = 1; i < n+1; i++) {
         for (size_t q = 1; q < m+1; q++) {
            resultStr += to_string(vmap[i][q]) + " ";
         }
         resultStr += "\n";
      }
      cout << resultStr << endl;*/

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
