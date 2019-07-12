#include <iostream>
#include <string>

using namespace std;

int dp[1001][1001];
int textLen;
int pattLen;

bool isMatch(int textInd, int pattInd, string text, string pattern)
{
  if(textInd == textLen)
  {
    for(int i = pattInd+1; i < pattLen; i+=2)
    {
      if(pattern[ i ] != '*') return false;
    }
    return true;
  }
  else if(pattInd == pattLen) return false;

  int &ret = dp[textInd][pattInd];
  if(ret != -1) return ret;
  ret = 0; // false;
  if(text[textInd] == pattern[pattInd] || pattern[pattInd] == '.')
  {
    if(pattInd+1 < pattLen && pattern[pattInd+1]=='*')
    {
      for(int i = textInd; i < textLen && text[i]==text[textInd]; i++)
      {
        ret += isMatch(i+1, pattInd+2, text, pattern);
      }
    }
    else
      ret += isMatch(textInd+1, pattInd+1, text, pattern);
  }
  else
  {
    if(pattInd+1 < pattLen && pattern[pattInd+1]=='*')
    {
      ret = isMatch(textInd, pattInd+2, text, pattern);
    }
  }

  return ret;
}

bool isMatch( const string &text, const string &pattern )
{
  textLen = text.length();
  pattLen = pattern.length();
  memset(dp, -1, sizeof dp);

  return isMatch(0, 0, text, pattern);   // first 0 is for text, last 0 is for pattern;
}

int main() {
  cout << isMatch("aa", "a") << endl;
  cout << isMatch("aa", "aa") << endl;
  cout << isMatch("abc", "a.c") << endl;
  cout << isMatch("abbb", "ab*") << endl;
  cout << isMatch("acd", "ab*c.") << endl;

  cout << isMatch("acd", "a*") << endl;


  return 0;
}


/*

aaaaaaaaaaaaaaa
aa*a*

patt: ab***

Don't worry about it :)

'*' <- not valid
'.*' <- valid
'a*' <- valid

'*' is matched for a "zero" or more sequence of the previous letter <----

text = "acd", pattern = "ab*c."


b*

'' <--> 'aaaa' not valid
'abc' <--> 'abcd*' true
'abcddd' <--> 'abcd*' true
'abc dd a d' <--> 'abc d* .* .' false
'abce' <--> 'abcd*.' true


 b*

 // idea

 d
 .

 0 <- text
 0 <- pattern




 */
