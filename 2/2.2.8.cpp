unsigned gcd(unsigned a, unsigned b)
{
   if(b==0)return a;
   unsigned c=a%b;
   a=b;
   b=c;
   gcd(a,b);
}