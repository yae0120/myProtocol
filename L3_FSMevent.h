typedef enum L3_event
{
    L3_event_PARINFO = 0, 
    L3_event_PARCNF = 1,  
    L3_event_RSREQ = 2,  
    L3_event_RESREQ = 3,
    L3_event_recfgSrcIdCnf = 4
    //L3_event_timer1 = 5,
    //L3_event_timer2 = 6,
    L3_event_timeout1 = 7,
    //L3_event_timeout2 = 8,
    L3_event_msgRcvd = 9,
    L3_event_dataSendCnf = 10
   
   
} L3_event_e;



void L3_event_setEventFlag(L3_event_e event);
void L3_event_clearEventFlag(L3_event_e event);
void L3_event_clearAllEventFlag(void);
int L3_event_checkEventFlag(L3_event_e event);


