#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/*
I hate this project. I hate it from the depths of my soul.
The only reason why Im continuing this project isntead of doing anything
else is coz I dont have any better project idea. But cause of my boredom, this code
is awful and crime against the C programming language
*/


//global variables
    struct fn {
    char name;
    char code[1024];
    };

//is there a standard function for that?
int last_filled_element_in_fn_array(struct fn ls[1024]){
    for(int x=0;x<=1024;x++){
        if(ls[x].code[0]==0) return x;
    }
}
char* char_to_string(char c) {
    char* fin=(char*)malloc(2 * sizeof(char));
    fin[0]=c;
    fin[1]='\0';
    return fin;
}

char* replace_all_char_instances_with_string(char character, char* original, char* replacement){
    char*fin=malloc(strlen(original)*sizeof(char)*2+strlen(replacement)+2); fin[0]='\0';
    for(int x=0;x<strlen(original);x++){
        if(original[x]==character){
            strcat(fin, replacement);
        }
        else strcat(fin, char_to_string(original[x]));
    }
    return fin;
}
bool is_in_char(char element, char*e_array){
    int x=0;
    while(e_array[x]!='\0'){
        if(e_array[x]==element) return 1;
        x++;
    }
    return 0;
}
// compiling functions
char* translate_num_pos(int target){
    int t=0; 
    char* out=malloc(20*sizeof(char)); out[0]='\0';
    //DO. NOT. ASK. Yes, I know what a for loop is
    while(t< floor(sqrt(target))){
        strcat(out, "+");
        t++;
    }

    char*fin=malloc((target+15)*sizeof(char));
    fin[0]='\0';
    //Format the brainfk output
    strcat(fin,out);
    strcat(fin,"[>");
    strcat(fin,out);
    strcat(fin,"<-]>");
    //append the remainder
    for(int x=target-t*t; x>0;x--){
        strcat(fin, "+");
    }

    return fin;
}
char* translate_num_neg(int target){
    //works similar to translate_pos
    int t=0;
    char* out1=malloc(20*sizeof(char)); out1[0]='\0';
    char* out2=malloc(20*sizeof(char)); out2[0]='\0';

    while(t<floor(sqrt(target))){
        strcat(out1, "+");
        strcat(out2, "-");
        t++;
    }
    char*fin=malloc((target+15)*sizeof(char));
    fin[0]='\0';

    strcat(fin,">");
    strcat(fin,out1);
    strcat(fin,"[<");
    strcat(fin,out2);
    strcat(fin,">-]<");
    for(int x=target-t*t; x>0;x--){
        strcat(fin, "-");
    }

    return fin;
}
//to_go - problem:
/* DOES. NOT. WORK.
char*load_modules(char*in){
    char*out=malloc(strlen(in)*sizeof(char)*2); out[0]='\0';
    char*fl=malloc(strlen(in)*sizeof(char)*2); fl[0]='\0';
    bool t_prep=false;
    for(int x=0;x<strlen(in); x++){
       if(in[x]=='_') t_prep=true;        
        if(in[x]==' ') t_prep=false;

       if(t_prep==false)strcat(out,char_to_string(in[x]));
        if(t_prep==true && in[x] != '_')strcat(fl,char_to_string(in[x]));
    }
    FILE*f=fopen(fl,"r");
    char*fc=malloc(10240);
    if(f!=NULL){
        fgets(fc,10240,f);
        return strcat(fc, out);
    }
    else {
        printf("\n/WARNING/ invalid import\n");
        return "inv";
    }
}*/
char*subroutines(char*in){
    static struct fn ls[1024];
    //printf()
    char*fin=malloc(420*strlen(in));
    char*fun=malloc(69*strlen(in));
    bool t_subr_prog=0;
    static char fun_c;
    for(int x=1;x<strlen(in); x++){
        if(in[x]=='('){
            t_subr_prog=true;
            fun_c=in[x-1];
        }
        if(t_subr_prog==true) strcat(fun,char_to_string(in[x]));
        strcat(fin,char_to_string(in[x]));
        if(in[x]==')' && t_subr_prog==true){
        t_subr_prog=false;
        fin=realloc(fin,strlen(fin)+strlen(fun)+10);
        ls[last_filled_element_in_fn_array(ls)].name=fun_c;
        strcpy(ls[last_filled_element_in_fn_array(ls)].code,fun);
        strcpy(fun,"");
    }
    }

        for(int y=0; y<1024;y++){
        if(ls[y].code[0]!='\0'){
            //printf("%c;%s\n",ls[y].name,ls[y].code);
            strcpy(fin, replace_all_char_instances_with_string(ls[y].name,fin,ls[y].code));
            
            }
        }
    return fin; //returbs >>> #
}

void compile(char input[]){
    size_t outsize=100*sizeof(char);
    char*fin=malloc(outsize);
    char code[10240]=""; strcpy(code,subroutines(input));
    size_t t_numerals_size=10*sizeof(char);
    char*t_numerals=malloc(t_numerals_size); t_numerals[0]='\0';
    char numeric_c[]={'0','1','2','3','4','5','6','7','8','9','\0'};
    char bad_fc[]={'>','<','^','v','[',']','_','.',',','+','-','*','\'','(',')','\0'};

    int t_text=0;
    int t_comment=0;
    //prepare for *really poorly* written code here
    for(int x=0; x<strlen(code);x++){
        if(code[x]=='*'){
            if(t_comment==0) t_comment=1;
            else if(t_comment==1) t_comment=0;
        }
        if(t_comment==0){
            if(code[x]=='\''){
                if(t_text==0) t_text=1;
                else if(t_text==1) t_text=0;
            }

            if(code[x]!="'"[0] && t_text==1){
                outsize+=100*sizeof(char); fin=realloc(fin, outsize);
                //printf("%s.>",translate_num_pos(code[x]));
                fin=strcat(fin, translate_num_pos(code[x]));
                fin=strcat(fin, ".>");
             }
             //printf("%c", code [x]);
            if((code[x]=='^' || code[x]=='v') && t_text==0 && t_comment==0){
                char t_mark=code[x];
                free(t_numerals);
                t_numerals_size=200*sizeof(char);
                t_numerals=malloc(t_numerals_size); t_numerals[0]='\0';
                x++;
                //Thanks C for forcing me to do this "clean" and "efficient" workaround 
                int t_index=0;
                while(is_in_char(code[x],numeric_c)){
                    t_numerals_size+=5*sizeof(char);
                    t_numerals=realloc(t_numerals, t_numerals_size);
                    t_numerals[t_index]=code[x];
                    //printf("%c",code[x]);
                    t_index++;
                    x++;
                }
                printf("%c",t_mark);
                if(t_mark == 'v')strcat(fin,translate_num_neg(atoi(t_numerals)));
                else strcat(fin,translate_num_pos(atoi(t_numerals)));
                //printf("%i",atoi(t_numerals));
            }
            strcat(fin,char_to_string(code[x]));
        }
    }
    //printf("\n %u", is_in_char('6', numeric_c));

    printf("%s",fin);

}
