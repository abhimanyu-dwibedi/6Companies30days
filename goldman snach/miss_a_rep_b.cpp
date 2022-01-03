class Solution{
public:
    int *findTwoElement(int *arr, int n) {
       int hass[n+1];
       for(int i=0;i<n+1;i++){
           hass[i]=0;
       }
       for(int i=0;i<n;i++){
           hass[arr[i]]++;
       }
       int *ret=new int[2];
       for(int i=1;i<n+1;i++){
          if(hass[i]==0){
              ret[1]=i;
               
          }
          if(hass[i]>=2){
              ret[0]=i;
          }
       }
       return ret;
    }
};