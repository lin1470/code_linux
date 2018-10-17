#include<stdio.h> /* EOF(=^Z??F6),NULL */
#include<math.h> /* floor(),ceil(),abs() */
/* ????????????? */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status; /* Status???????????,???????????????????OK?? */
typedef struct
{
  char *ch; /* ???????,?????????��??,????ch?NULL */
  int length; /* ?????? */
}HString;
Status StrAssign(HString *T,char *chars)
{ /* ???????????????????chars???T */
  int i,j;
  if((*T).ch)
    free((*T).ch); /* ???T??��?? */
  i=strlen(chars); /* ??chars?????i */
  if(!i)
  { /* chars??????0 */
    (*T).ch=NULL;
    (*T).length=0;
  }
  else
  { /* chars???????0 */
    (*T).ch=(char*)malloc(i*sizeof(char)); /* ??????? */
    if(!(*T).ch) /* ?????????? */
      exit(OVERFLOW);
    for(j=0;j<i;j++) /* ?????? */
      (*T).ch[j]=chars[j];
    (*T).length=i;
  }
  return OK;
}
Status StrCopy(HString *T,HString S)
{ /* ???????:??S????????????: ???S??????T */
  int i;
  if((*T).ch)
    free((*T).ch); /* ???T??��?? */
  (*T).ch=(char*)malloc(S.length*sizeof(char)); /* ??????? */
  if(!(*T).ch) /* ?????????? */
    exit(OVERFLOW);
  for(i=0;i<S.length;i++) /* ?????? */
    (*T).ch[i]=S.ch[i];
  (*T).length=S.length;
  return OK;
}
Status StrEmpty(HString S)
{ /* ???????: ??S????????????: ??S????,???TRUE,?????FALSE */
  if(S.length==0&&S.ch==NULL)
    return TRUE;
  else
    return FALSE;
}

int StrCompare(HString S,HString T)
{ /* ??S>T,????>0;??S=T,????=0;??S<T,????<0 */
  int i;
  for(i=0;i<S.length&&i<T.length;++i)
    if(S.ch[i]!=T.ch[i])
      return S.ch[i]-T.ch[i];
  return S.length-T.length;
}

int StrLength(HString S)
{ /* ????S????????,?????????? */
  return S.length;
}

Status ClearString(HString *S)
{ /* ??S?????? */
  if((*S).ch)
  {
    free((*S).ch);
    (*S).ch=NULL;
  }
  (*S).length=0;
  return OK;
}

Status SubString(HString *Sub, HString S,int pos,int len)
{ /* ??Sub?????S???pos?????????len??????? */
  /* ????,1??pos??StrLength(S)??0??len??StrLength(S)-pos+1 */
  int i;
  if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
    return ERROR;
  if((*Sub).ch)
    free((*Sub).ch); /* ?????? */
  if(!len) /* ????? */
  {
    (*Sub).ch=NULL;
    (*Sub).length=0;
  }
  else
  { /* ??????? */
    (*Sub).ch=(char*)malloc(len*sizeof(char));
    if(!(*Sub).ch)
      exit(OVERFLOW);
    for(i=0;i<=len-1;i++)
      (*Sub).ch[i]=S.ch[pos-1+i];
    (*Sub).length=len;
  }
  return OK;
}

void InitString(HString *T)
{ /* ?????(???????)?????T????? */
  (*T).length=0;
  (*T).ch=NULL;
}

int Index(HString S,HString T,int pos) 
{ /* T?????????????S?��?pos?????????????T???????, */
  /* ??????????????????S?��?��??,?????0 */
  int n,m,i;
  HString sub;
  InitString(&sub);
  if(pos>0)
  {
    n=StrLength(S);
    m=StrLength(T);
    i=pos;
    while(i<=n-m+1)
    {
      SubString(&sub,S,i,m);
      if(StrCompare(sub,T)!=0)
         ++i;
      else
         return i;
    }
  }
  return 0;
 }

Status StrInsert(HString *S,int pos,HString T)
{ /* 1??pos??StrLength(S)+1?????S???pos???????????T */
  int i;
  if(pos<1||pos>(*S).length+1) /* pos????? */
    return ERROR;
  if(T.length) /* T???,?????��?????,????T */
  {
    (*S).ch=(char*)realloc((*S).ch,((*S).length+T.length)*sizeof(char));
    if(!(*S).ch)
      exit(OVERFLOW);
    for(i=(*S).length-1;i>=pos-1;--i) /* ?????T?????��?? */
      (*S).ch[i+T.length]=(*S).ch[i];
    for(i=0;i<T.length;i++)
      (*S).ch[pos-1+i]=T.ch[i]; /* ????T */
    (*S).length+=T.length;
  }
  return OK;
}

Status StrDelete(HString *S,int pos,int len)
{ /* ???S???????pos?????????len????? */
  int i;
  if((*S).length<pos+len-1)
    exit(ERROR);
  for(i=pos-1;i<=(*S).length-len;i++)
    (*S).ch[i]=(*S).ch[i+len];
  (*S).length-=len;
  (*S).ch=(char*)realloc((*S).ch,(*S).length*sizeof(char));
  return OK;
}
void StrPrint(HString T)
{ /* ???T?????????? */
  int i;
  for(i=0;i<T.length;i++)
    printf("%c",T.ch[i]);
  printf("\n");
}
#define MAX_LEN 25 /* ?????????? */
#define LINE_LEN 75 /* ????????????+1 */
#define NAME_LEN 20 /* ?????????(?????????��??)+1 */

/* ?????? */
HString T[MAX_LEN];
char str[LINE_LEN],filename[NAME_LEN]="";
FILE *fp;
int n=0; /* ??????? */

void Open()
{ /* ?????(????) */
  int i;
  if(filename[0]) /* ?????? */
    printf("??????????\n");
  else
  {
    printf("???????????(??????????��??????????%d?????): ",NAME_LEN-1);
    scanf("%s%*c",filename);
    fp=fopen(filename,"r");
    if(fp) /* ????????? */
    {
      do
      {
        fgets(str,LINE_LEN,fp);
        i=strlen(str);
        str[i-1]=0; /* ??10?????0 */
        i--;
        if(i>0)
        {
          StrAssign(&T[n],str);
          n++;
          if(n>MAX_LEN)
          {
            printf("??????\n");
            return;
          }
        }
      }while(i>0);
      fclose(fp);
    }
    else
      printf("?????\n");
  }
}

void List()
{ /* ?????????? */
  int i;
  for(i=0;i<n;i++)
  {
    printf("%d: ",i+1);
    StrPrint(T[i]);
  }
  getchar();
}

void Insert()
{ /* ?????? */
  int i,l,m;
  printf("???l?????m??,??????l m: ");
  scanf("%d%d%*c",&l,&m);
  if(n+m>MAX_LEN)
  {
    printf("?????????\n");
    return;
  }
  if(n>=l-1&&l>0)
  {
    for(i=n-1;i>=l-1;i--)
      T[i+m]=T[i];
    n+=m;
    printf("??????????????????:\n");
    for(i=l-1;i<l-1+m;i++)
    {
      gets(str);
      InitString(&T[i]);
      StrAssign(&T[i],str);
    }
  }
  else
    printf("?��?????��\n");
}

void Delete()
{ /* ????? */
  int i,l,m;
  printf("???l???????m??,??????l m: ");
  scanf("%d%d%*c",&l,&m);
  if(n>=l+m-1&&l>0)
  {
    for(i=l-1+m;i<n;i++)
      T[i-m]=T[i];
    for(i=n-m;i<n;i++)
      InitString(&T[i]);
    n-=m;
  }
  else
    printf("?��?????��\n");
}

void Copy()
{ /* ?????? */
  int i,l,m,k;
  printf("???l?��????m?��????k????,??????l m k: ");
  scanf("%d%d%d%*c",&l,&m,&k);
  if(n+m>MAX_LEN)
  {
    printf("?????????\n");
    return;
  }
  if(n>=k-1&&n>=l-1+m&&(k>=l+m||k<=l))
  {
    for(i=n-1;i>=k-1;i--)
      T[i+m]=T[i];
    n+=m;
    if(k<=l)
      l+=m;
    for(i=l-1;i<l-1+m;i++)
    {
      InitString(&T[i+k-l]);
      StrCopy(&T[i+k-l],T[i]);
    }
  }
  else
    printf("?��?????��\n");
}

void Modify()
{ /* ????? */
  int i;
  printf("????????????��?: ");
  scanf("%d%*c",&i);
  if(i>0&&i<=n) /* ?��??? */
  {
    printf("%d: ",i);
    StrPrint(T[i-1]);
    printf("????????????: ");
    gets(str);
    StrAssign(&T[i-1],str);
  }
  else
    printf("?��??????��\n");
}

void Search()
{ /* ????????? */
  int i,k,f=1; /* f??????????? */
  char b;
  HString s;
  printf("?????????????????: ");
  scanf("%s%*c",str);
  InitString(&s);
  StrAssign(&s,str);
  for(i=0;i<n&&f;i++) /* ???��??? */
  {
    k=1; /* ????��?1?????????? */
    while(k)
    {
      k=Index(T[i],s,k); /* ????��??k???????????? */
      if(k) /* ??? */
      {
        printf("??%d??: ",i+1);
        StrPrint(T[i]);
        printf("??%d??????????????????????(Y/N)? ",k);
        b=getchar();
        getchar();
        if(b!='Y'&&b!='y') /* ?��???? */
        {
          f=0;
          break;
        }
        else
          k++;
      }
    }
  }
  if(f)
    printf("????\n");
}

void Replace1()
{ /* ?�I????? */
  int i,k,f=1; /* f??????�I??? */
  char b;
  HString s,t;
  printf("????????�I???????: ");
  scanf("%s%*c",str);
  InitString(&s);
  StrAssign(&s,str);
  printf("?�I?: ");
  scanf("%s%*c",str);
  InitString(&t);
  StrAssign(&t,str);
  for(i=0;i<n&&f;i++) /* ???��?????�I */
  {
    k=1; /* ????��?1?????????? */
    while(k)
    {
      k=Index(T[i],s,k); /* ????��??k???????????? */
      if(k) /* ??? */
      {
        printf("??%d??: ",i+1);
        StrPrint(T[i]);
        printf("??%d????????????????�I(Y/N)? ",k);
        b=getchar();
        getchar();
        if(b=='Y'||b=='y')
        {
          StrDelete(&T[i],k,StrLength(s));
          StrInsert(&T[i],k,t);
        }
        printf("?????�I??(Y/N)?");
        b=getchar();
        getchar();
        if(b!='Y'&&b!='y') /* ?��??????�I */
        {
          f=0;
          break;
        }
        else
          k+=StrLength(t);
      }
    }
  }
  if(f)
    printf("????\n");
}

void Save()
{ /* ???? */
  int i;
  getchar();
  fp=fopen(filename,"w");
  if(fp)
  {
    for(i=0;i<n;i++)
    {
      T[i].ch[T[i].length]=0;
      fputs(T[i].ch,fp);
      fputc(10,fp);
    }
    fputc(10,fp);
    fclose(fp);
  }
  else
    printf("???????\n");
}

void main()
{
  Status s=TRUE;
  int i,k;
  for(i=0;i<MAX_LEN;i++) /* ??????? */
    InitString(&T[i]);
  while(s)
  {
    printf("?????: 1.?????(????)  2.??????????\n");
    printf("        3.??????  4.?????  5.??????  6.?????\n");
    printf("        7.?????????        8.?�I?????\n");
    printf("        9.???????          0.??????\n");
    scanf("%d",&k);
    switch(k)
    {
      case 1: Open();
              break;
      case 2: List();
              break;
      case 3: Insert();
              break;
      case 4: Delete();
              break;
      case 5: Copy();
              break;
      case 6: Modify();
              break;
      case 7: Search();
              break;
      case 8: Replace1();
              break;
      case 9: Save();
      case 0: s=FALSE;
    }
  }
}