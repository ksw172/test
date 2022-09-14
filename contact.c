#include<stdio.h>
#include<string.h>
enum {
    EXIT,
    INSERT,
    SEARCH,
    DELETE,
    CORRECTION
};
typedef struct member{
    char name[30];
    int tel[30];
}Member;
Member arr[20] ={
        {"홍길동"},
        {"김철수"},
        {"이학우"},
};
int idx = 3; 
void InsertMember(){
    if(idx == 20){
        printf("더이상 저장할 공간이 없습니다\n");
        return;
    }
    printf("이름");
    scanf(" %s",arr[idx].name);
    printf("전화번호");
    scanf(" %d",&arr[idx].tel);
    idx++;
    printf("연락처 등록\n");
}
void PrintAllMember(){
    printf("전체 회원정보 출력\n\n");
    for(int i=0;i<idx;i++)
    printf("%s %d %c\n",arr[i].name, arr[i].tel);
    printf("\n");
}
void SearchMember(){
    char str[30];
    printf("검색 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            printf("%s %d %c\n",arr[i].name, arr[i].tel);
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");
}
void DeleteMember(){
     char str[30];
    printf("삭제 : ");
    scanf("%s",str);
    for(int i=0;i<idx;i++){
        if(strcmp(arr[i].name,str) == 0){
            for(int j=i;j<idx-1;j++)
                arr[j] = arr[j+1];
            
            return;
        }
    }
    printf("검색 결과가 없습니다.\n");    
}
void CorrectionMember(){
        char str[30];
      printf("수정 : ");
      scanf("$s", str);
      for(int i=0;i<idx;i++){
        if (strcmp(arr[i].name,str) == 0){
            for(int j=i;j<idx-1;j++)
            arr[j] = arr[j+1];

            return;
        }
      }
      printf("검색 결과가 없습니다.\n");
}
int main(void){
    int no  = -1;

    while(no != EXIT){
        puts("-----연락처를 저장하는 프로그램----");
        puts("1.연락처 등록");
        puts("2. 연락처 검색");
        puts("3. 연락처 삭제");
        puts("4. 연락처 수정");
        scanf("%d",&no);

        switch(no){
            case INSERT:
                InsertMember();
                break;
            case SEARCH:
                SearchMember();
                break;
            case DELETE:
                DeleteMember();
                break;
            case CORRECTION:
                PrintAllMember();
                break;    
        }
    }
    return 0;
}