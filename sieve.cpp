ll n = 1e7;
for(int i =2; i*i<=n; i++)
{
    if(prime[i]==0)
    {
        for(int j=i*i; j<=n; j+=i)
        {
            prime[j]=1;
        }
    }
}
for(int i=2; i<=n; i++)
{
    if(prime[i]==0)
    {
        pr.pb(i);
    }
}
cout<<pr.size()<<endl;
