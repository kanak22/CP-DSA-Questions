string temp(string s)
{
    for(int j=0;j<s.length();j++)
        {
          for(int k=j+1;k<s.length();k++)
          {
              int f=s[j]-'a';
              int en=s[k]-'a';
              if(f>en)
              {
                  return "YES";
            
              }
          }        
    
          }
          return "NO";
    
}

vector<string> possibleChanges(vector<string> usernames) {
    
    int n=usernames.size();
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        string s=usernames[i];
        ans.push_back(temp(s));
        
        
    }
    return ans;

}
