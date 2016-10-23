class Solution {
public:
/** 
* @param chars: The letters array you should sort.
*/
void sortLetters(string &letters) {
// write your code here

if(!letters.size())
return;

int i = 0;
int j = letters.size() - 1;
char temp;

while(1)
{
while(letters[i] >= 'a' && letters[i] <= 'z') i++;
while(letters[j] >= 'A' && letters[j] <= 'Z') j--;

if(i < j)
{
temp = letters[i];
letters[i] = letters[j];
letters[j] = temp;
i ++;
j --;
}

if(i >= j)
{
return;
}
}
}
};
