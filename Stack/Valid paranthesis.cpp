
//valid paranthesis
bool validparanthesis(string str){
stack<int>s;
for(int i=0;i<str.size();i++){
//pushing /opening brackets
if(str[i]=='(' || str[i]=='{' ||str[i]=='['){
  s.push(str[i]);
    continue;
}
//popping/closing brackets
if(str[i]==')' && s.top()=='('){
  s.pop();

}
else if(str[i]=='}' && s.top()=='{'){
  s.pop();
}else if(str[i]==']' && s.top()=='['){
  s.pop();
} else{
  return false;
}
}
if(s.empty()){
  return true;
}
else{
  return false;
}

}