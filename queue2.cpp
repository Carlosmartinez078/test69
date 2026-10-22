#include <queue>

void RotateQueue(std::queue<int>& requests, int k) {
  if (requests.empty() || k == 0){
    return;
  }

  int n = requests.size();

  k = n % n;
  if (k == 0){
    return;
  }
  
  for (int i = 0; i < k; i++) {
    cout << 
  }
  
  
}



int main(){

    return 0;
}