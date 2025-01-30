 
class Solution {
    encode(s){
        // code here
       let encodedStr = '';
       let count = 1;
       
       //Traverse through the string
       for(let i = 1; i < s.length; i++){
           //check if current is same as prev
           if(s[i] == s[i-1]){
               count++;
           } else {
               //append prev and count to result
               encodedStr += s[i-1] + count;
               count = 1;   //reset ccount for new character
           }
       }
       //append last character and its count
       encodedStr += s[s.length - 1] + count;
       
       return encodedStr;
    }
}
