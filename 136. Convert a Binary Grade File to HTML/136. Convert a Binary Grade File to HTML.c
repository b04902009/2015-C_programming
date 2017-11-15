#include <stdio.h>
typedef struct{
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;
int main()
{
    char name_in[80],name_out[80];
    scanf("%s%s",name_in,name_out);
    FILE *fin = fopen(name_in, "rb");
    FILE *fout = fopen(name_out, "wb");
    Student s;

    fputs("<table border=\"1\">\n<tbody>\n",fout);
    while(fread(&s,sizeof(Student),1,fin)){
        fprintf(fout,"<tr>\n<td>%s</td>\n",s.name);
        fprintf(fout,"<td>%d</td>\n",s.id);
        fprintf(fout,"<td>%s</td>\n",s.phone);
        fprintf(fout,"<td>%f, %f, %f, %f</td>\n",s.grade[0],s.grade[1],s.grade[2],s.grade[3]);
        fprintf(fout,"<td>%d, %d, %d</td>\n</tr>\n",s.birth_year,s.birth_month,s.birth_day);
    }
    fputs("</tbody>\n</table>\n",fout);

    fclose(fout);
    fclose(fin);
    return 0;
}










