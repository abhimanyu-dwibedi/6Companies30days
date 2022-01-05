ode here 
  string ans="";
  ans+=src[0];
  int count=1;
  for(int i=1;i<src.length();i++){
       if(src[i]!=src[i-1]){
           ans+=to_string(count);
           count=1;
           ans+=src[i];
           continue;
       }
       count++;
  }
  ans+=to_string(count);
  return ans;
}     
 