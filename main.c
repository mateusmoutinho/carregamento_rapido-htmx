#include "CWebStudio.h"
#include "doTheWorld.h"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    long valor_anterior =dtw_load_long_file_content("valor");
    if(strcmp(request->route,"/incrementa") ==0){
        valor_anterior+=1;
        dtw_write_long_file_content("valor",valor_anterior);
    }
   
   if(strcmp(request->route,"/decrementa") ==0){
        valor_anterior-=1;
        dtw_write_long_file_content("valor",valor_anterior);
    }


    char convertido[20] ={0};
    sprintf(convertido,"%d",valor_anterior);
    return cweb_send_text(convertido,200);

    
    

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5000, main_sever);
    cweb.server.start(&server);
    return 0;
}