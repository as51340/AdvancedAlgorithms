#include<bits/stdc++.h>

using namespace std;

#define num 26

struct Node 
{ 
    struct Node *children[num]; 
    bool leaf;
}; 
  
// Returns new trie node (initialized to NULLs) 
struct Node *getNode(void) 
{ 
    struct Node *pNode =  new Node; 
  
    pNode->leaf = false; 
  
    for (int i = 0; i < num; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
}

void insert(struct Node *root, string key) 
{ 
    struct Node *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
  
    pCrawl->leaf = true; 
} 
  
bool search(struct Node *root, string key,bool flag, int i) 
{ 
    struct Node *pCrawl = root; 
  
    for (;i < key.length(); i++) {
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index])  {
            if(flag == true) {
				//cout << "Tu nismo nikad" << endl;
				return false;
			}
			else {
				struct Node *tmpNode = pCrawl;
				bool flagGen = false;
				for(int j = 0; j < num; j++) {
					if(!tmpNode->children[j]) {
						continue;
					}
					else {
						bool flagSearch = search(tmpNode->children[j],key,true,i+1);
						if(flagSearch == true) {
							flagGen = true;
							return true;
						}
					}
				}
				if(flagGen == false)
					return false;
			}
		}
		pCrawl = pCrawl->children[index];
	}
    return (pCrawl != NULL && pCrawl->leaf); 
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	struct Node *root = getNode();
	string s;
	for(int i = 0; i < n; i++) {
		cin >> s;
		insert(root, s);
	}
	
	for(int i = 0; i < m; i++) {
		cin >> s;
		if(search(root, s,false,0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}
		















 
  