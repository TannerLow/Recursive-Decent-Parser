# Recursive-Decent-Parser
Basic recursive decent parser for checking if a set is written properly  

Grammar:
* Set : { List }  
* List: Head Tail | e  
* Head: number | Set  
* Tail: , Head Tail | e  

Ex.  
* {1,2,3,{}} -> true  
* {1,2}      -> true  
* {123,456}} -> false
