#include "CWebStudio.h"
#include "doTheWorld.h"
CwebNamespace cweb;

CwebHttpResponse *main_sever(CwebHttpRequest *request ){

    long valor_anterior =dtw_load_long_file_content("valor");
    if(strcmp(request->route,"/incrementa") ==0){
        valor_anterior+=1;
        dtw_write_long_file_content("valor",valor_anterior);
        return cweb_send_text("ok",200);

    }
   
   if(strcmp(request->route,"/decrementa") ==0){
        valor_anterior-=1;
        dtw_write_long_file_content("valor",valor_anterior);
        return cweb_send_text("ok",200);
    }
    if(strcmp(request->route,"/visualiza") ==0){
         char convertido[20] ={0};
        sprintf(convertido,"%ld",valor_anterior);
        return cweb_send_text(convertido,200);
    }
    

    return cweb.response.send_file("index.html",CWEB_AUTO_SET_CONTENT,200);

    
    

}

int main(int argc, char *argv[]){
    cweb = newCwebNamespace();
    struct CwebServer server = newCwebSever(5002, main_sever);
    cweb.server.start(&server);
    return 0;
}