#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int n;
int f;
void printheaderfifo(){
    cout<<"Replacement Policy = FIFO\n";
    cout<<"-------------------------------------\n";
    cout<<"Page   Content of Frames\n";
    cout<<"----   -----------------\n";
}
void printheaderlru(){
    cout<<"Replacement Policy = LRU\n";
    cout<<"-------------------------------------\n";
    cout<<"Page   Content of Frames\n";
    cout<<"----   -----------------\n";
}
void printheaderclk(){
    cout<<"Replacement Policy = CLOCK\n";
    cout<<"-------------------------------------\n";
    cout<<"Page   Content of Frames\n";
    cout<<"----   -----------------\n";
}
void printheaderopt(){
    cout<<"Replacement Policy = OPTIMAL\n";
    cout<<"-------------------------------------\n";
    cout<<"Page   Content of Frames\n";
    cout<<"----   -----------------\n";
}
void fifo (){
    printheaderfifo();
    int arr[n];
    memset(arr,-1,sizeof(arr));
    int sz=0;
    int fr=0;
    int x;
    while(cin>>x&&~x){
        if(x&&x<10)cout<<0;
        cout<<x<<" ";
        bool fnd=0;
        for(int i=0;i<n;i++){
            if(arr[i]==x)fnd=1;
        }
        if(fnd){
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
        }
        if(!fnd&&sz!=n){
            arr[fr+sz]=x;
            sz++;
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;

        }
        if(!fnd&&sz==n){
            f++;
            cout<<"F   ";
            arr[fr%n]=x;
            fr++;
            for(int i=0;i<n;i++){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
        }

    }
    cout<<"-------------------------------------\n";
    cout<<"Number of page faults = "<<f<<"\n";
}
void lru(){
    printheaderlru();
    int arr[n];
    int freq[100005];
    memset(freq,0,sizeof(freq));
    memset(arr,-1,sizeof(arr));
    int sz=0;
    int fr=0;
    int cnt=0;
    int x;
    while(cin>>x&&~x){
        cnt++;
        if(x&&x<10)cout<<0;
        cout<<x<<" ";
        bool fnd=0;
        for(int i=0;i<n;i++){
            if(arr[i]==x)fnd=1;
        }
        if(fnd){
            freq[x]=cnt;
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
        }
        if(!fnd&&sz!=n){
            freq[x]=cnt;
            arr[fr+sz]=x;
            sz++;
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;

        }
        if(!fnd&&sz==n){
            f++;
            cout<<"F   ";
            int mn=INT_MAX;
            int idx;
            for(int i=0;i<n;i++){
                if(freq[arr[i]]<mn){
                    mn=freq[arr[i]];
                    idx=i;
                }
            }
            arr[idx]=x;
            freq[x]=cnt;
            for(int i=0;i<n;i++){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
        }

    }
    cout<<"-------------------------------------\n";
    cout<<"Number of page faults = "<<f<<"\n";

}
void clk(){
    printheaderclk();
    int arr[n];
    bool freq[100005];
    memset(freq,0,sizeof(freq));
    memset(arr,-1,sizeof(arr));
    int sz=0;
    int fr=0;
    int cnt=0;
    int x;
    while(cin>>x&&~x){
        if(x&&x<10)cout<<0;
        cout<<x<<" ";
        bool fnd=0;
        for(int i=0;i<n;i++){
            if(arr[i]==x)fnd=1;
        }
        if(fnd){
            freq[x]=1;
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
        }
        if(!fnd&&sz!=n){
            freq[x]=1;
            arr[fr+sz]=x;
            sz++;
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;

        }
        if(!fnd&&sz==n){
            f++;
            cout<<"F   ";
            while(1){
                if(freq[arr[cnt]]){
					freq[arr[cnt]]=0;
					cnt=(cnt+1)%n;
					continue;
				}
				if(!freq[arr[cnt]]){
					arr[cnt]=x;
					freq[arr[cnt]]=1;
					cnt=(cnt+1)%n;
					break;
				}

            }
            for(int i=0;i<n;i++){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
        }

    }
    cout<<"-------------------------------------\n";
    cout<<"Number of page faults = "<<f<<"\n";
}
void opt(){
printheaderopt();
vector<int> input;
int arr[n];
int next[n];
int inf=0x3f3f3f3f;
memset(next,inf,sizeof(next));
memset(arr,-1,sizeof(arr));
int sz=0;
int x;
while(cin>>x&&~x)input.emplace_back(x);
for(int j=0;j<input.size();j++){
	int num=input[j];
    if(num&&num<10)cout<<0;
    cout<<num<<" ";
    bool fnd=0;
    for(int i=0;i<n;i++)if(arr[i]==num)fnd=1;
    if(fnd){
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
    }
    if(!fnd&&sz!=n){
            arr[sz]=num;
            sz++;
            cout<<"    ";
            for(int i=0;i<n;i++)
            if(~arr[i]){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
    }
    if(!fnd&&sz==n){
    		f++;
            cout<<"F   ";
        for(int i=0;i<n;i++){
        	bool fond=0;
        	for(int k=j+1;k<input.size();k++){
        		if(arr[i]==input[k]){
        		next[i]=k;
        		fond=1;
        		break;
        		}
        	}
        	if(!fond)next[i]=inf;
        }
        int idx;
        int mx=-1;
        for(int i=0;i<n;i++){
        	if(next[i]>mx){
        		mx=next[i];
        		idx=i;
        	}
        }
        arr[idx]=num;
        for(int i=0;i<n;i++){
            if(arr[i]&&arr[i]<10)cout<<0;
            cout<<arr[i]<<" ";}
            cout<<"\n";
            continue;
    }
}
    cout<<"-------------------------------------\n";
    cout<<"Number of page faults = "<<f<<"\n";
}

int main()
{
    //freopen("inputOPTIMAL.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin>>n>>s;
    if(s[0]=='F')fifo();
    if(s[0]=='L')lru();
    if(s[0]=='C')clk();
    if(s[0]=='O')opt();

}
