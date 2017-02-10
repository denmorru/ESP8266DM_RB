void WEBprocessing(){
    if(GET_STATUS){TOSR04_Relay_Status();}
    TOSR04_Relay_Control();
    if(GET_STATUS){TOSR04_Relay_Status();}
    dm_print_webpage();
    HTTP.send(200,"text/html",webPageContent);
    webPageContent="";
}

void dm_print_webpage()
{
       webPageContent+="<div>";
       webPageContent+="<div style='width:100%;line-height:90px;float:left;'> ";
       webPageContent+=" ";
       dm_add_button(1,rstat[0]);
       dm_add_button(2,rstat[1]);
       dm_add_button(3,rstat[2]);
       dm_add_button(4,rstat[3]);
       webPageContent+="</div>";
       webPageContent+="<div style='width:100%;float:left;'><br><a href='";
       webPageContent+=baseurl;
       webPageContent+="' style='clear:both;'><h3>Refresh</h3></a>";
       webPageContent+="</div></div>";  
}

void dm_add_button(int butNum, int stat){
      if(stat)
                 {
                 webPageContent+="<a href='";
                 webPageContent+=baseurl;
                 webPageContent+="FF0";webPageContent+=butNum;webPageContent+="00' style='background-color:#FFFF66;";
                 webPageContent+=buttonstyle;
                 webPageContent+="'>OFF #";webPageContent+=butNum;webPageContent+="</a>";
                 }
        else
                 {
                 webPageContent+="<a href='";
                 webPageContent+=baseurl;
                 webPageContent+="FF0";webPageContent+=butNum;webPageContent+="01' style='background-color:#6666FF;";
                 webPageContent+=buttonstyle;
                 webPageContent+="'>ON #";webPageContent+=butNum;webPageContent+="</a>";
                 }
         webPageContent+=" ";
}
