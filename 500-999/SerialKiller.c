#include <stdio.h>
#include <string.h>

int main(){
    char victim1[11], victim2[11];
    char murdered[11], replacement[11];
    int n;
    scanf("%s %s",&victim1, &victim2);
    scanf("%d",&n);
    printf("%s %s\n", victim1, victim2);

    for (int i=0;i<n;i++){
        scanf("%s %s", &murdered, &replacement);
        if (!strcmp(victim1,murdered)) strcpy(victim1,replacement);
        else strcpy(victim2, replacement);
        printf("%s %s\n", victim1,victim2);
    }
    return 0;
}