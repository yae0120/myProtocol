#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int cnt = 0;

// ID 추출 함수
int getAssignedID(uint8_t* msg, int cnt) {
    int assignIDparticipant = 123; // 임의의 값 할당
    int assignIDexaminer = 456;
    int assignedID = -1; // 할당된 ID를 저장할 변수, 초기값 -1

    char* str = (char*)L3_getPARREQ_result1(msg);
    assignIDparticipant = atoi(str);

    if (cnt == 1) { //참가자일 때
        assignedID = assignIDparticipant;
    }

    else if (cnt == 2) { //출제자일 때
        assignIDexaminer = atoi(str);
        if (assignIDexaminer == assignIDparticipant) {
            assignIDexaminer++;
        }
        assignedID = assignIDexaminer;
    }

    return assignedID;
}

int main() {
    int myDestId_part;
    int myDestId_exam;
    //uint8_t msg[5] = { 0x00, '1', '9', '4', '\0' }; // 테스트용

    // 할당된 ID 출력 (참가자)
    myDestId_part = getAssignedID(msg, 1);
    std::cout << "Assigned ID for participant: " << myDestId_part << std::endl;

    // 할당된 ID 출력 (출제자)
    myDestId_exam = getAssignedID(msg, 2);
    std::cout << "Assigned ID for examiner: " << myDestId_exam << std::endl;


    return 0;
}