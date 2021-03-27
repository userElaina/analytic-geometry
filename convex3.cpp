//Code By 1677
#include<bits/stdc++.h>
#define LMX 9223372036854775807
#define IMX 2147483647
#define M0 1000000007
#define M9 998244353
#define M8 19260817
#define M7 7221457
#define PI 3.1415926
#define E 2.71828
#define LL long long
#define doublw double
#define ini int
#define itn int
#define calss class
#define pt putchar
#define gt getchar
#define lowbit(a) (a&(~a+1))
#define cmm(a,b) if(a^b){a^=b;b^=a;a^=b;}
#define lcm(a,b) (a/gcd(a,b)*b)
#define gcd(a,b) exgcd(a>b?a:b,a>b?b:a)
#define mn(a,b) (a<b?a:b)
#define mx(a,b) (a>b?a:b)
#define ab(a) (a>=0?a:(~a+1))
#define ED(a) (~scanf("%d",&a))
#define I(b,a,c) (a>=b&&a<=c)
inline LL exgcd(LL a,LL b){if(!b)return a;return exgcd(b,a%b);}
#define MXN 2333
#define var (1e-9)
#define rnd ((double)rand()/(double)RAND_MAX)
#define rv ((rnd-0.5)*var)
int v[MXN][MXN];
double ans;
class P{
public:
	double x,y,z;
	void ck(){x+=rv;y+=rv;z+=rv;}
	void pin(){scanf("%lf%lf%lf",&x,&y,&z);ck();}
	void ot(){printf("%.5lf %.5lf %.5lf\n",x,y,z);}
	double len(){return sqrt(x*x+y*y+z*z);}
	P operator+(P r){return (P){x+r.x,y+r.y,z+r.z};}
	P operator-(P r){return (P){x-r.x,y-r.y,z-r.z};}
	P operator/(P r){return (P){y*r.z-z*r.y,z*r.x-x*r.z,x*r.y-y*r.x};}
	double operator*(P r){return x*r.x+y*r.y+z*r.z;}
}p[MXN];
class S{
public:
	int v[3];
	void ot(){printf("%d %d %d\n",v[0],v[1],v[2]);}
	P sp(){return (p[v[1]]-p[v[0]])/(p[v[2]]-p[v[0]]);}
	double sa(){return sp().len()/2.0;}
	int ck(P pp){return ((pp-p[v[0]])*sp()>0);}
}s[MXN],ss[MXN];
int main(){
	int n,t=2;
	scanf("%d",&n);
	memset(v,0,sizeof(v));
	for(int i=0;i<n;i++)p[i].pin();
	s[0]=(S){0,1,2};
	s[1]=(S){2,1,0};
	int tt=0;
	for(int i=3;i<n;i++){
		int b;
		for(int j=0;j<t;j++){
			if(!(b=s[j].ck(p[i])))ss[tt++]=s[j];
			v[s[j].v[0]][s[j].v[1]]=v[s[j].v[1]][s[j].v[2]]=v[s[j].v[2]][s[j].v[0]]=b;
		}
		for(int j=0;j<t;j++){
			#define x s[j].v[0]
			#define y s[j].v[1]
			if(v[x][y]&&!v[y][x])ss[tt++]=(S){x,y,i};
			#undef x
			#undef y
			#define x s[j].v[1]
			#define y s[j].v[2]
			if(v[x][y]&&!v[y][x])ss[tt++]=(S){x,y,i};
			#undef x
			#undef y
			#define x s[j].v[2]
			#define y s[j].v[0]
			if(v[x][y]&&!v[y][x])ss[tt++]=(S){x,y,i};
			#undef x
			#undef y
		}
		for(int j=0;j<tt;j++)s[j]=ss[j];
		t=tt;tt=0;
	}
	if(t&1)printf("Error!");
	printf("These points' convex hull have %d vertexes, %d edges, %d faces.\n",2+(t>>1),t+(t>>1),t);
	for(int i=0;i<t;i++)ans+=s[i].sa();
	printf("And its superficial area is %.5lf.\n",ans);
}
