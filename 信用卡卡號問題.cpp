#include <iostream>
using namespace std;
int isVisa(int digitalCardNumber[],int totalDigital){
    int result = 0;  
    if(totalDigital == 13 || totalDigital == 16){
        if(digitalCardNumber[totalDigital] == 4){
            result = 1;
        }
    }
    return result;
}
int isMaster(int digitalCardNumber[],int totalDigital){
  int result = 0;  
  if( totalDigital == 16){
      if(digitalCardNumber[totalDigital] == 5){
          if((digitalCardNumber[totalDigital - 1] >0) && (digitalCardNumber[totalDigital - 1] < 6)){
            result = 1;
          }
      }
  }
  return result;
}
int isAE(int digitalCardNumber[],int totalDigital){
    int result = 0;  
    if(totalDigital == 15){
        if(digitalCardNumber[totalDigital] == 3){
            if((digitalCardNumber[totalDigital - 1] == 4) || (digitalCardNumber[totalDigital - 1] == 7)){
           result = 1;
            }
        }
    }
    return result;
}
int caculate(int digitalCardNumber[], int totalDigital){
    //表偶位個數
    int sum = 0;
    for(int j = 2; j <= totalDigital; j = j + 2){
        digitalCardNumber[j] = digitalCardNumber[j] * 2;
        sum = sum + digitalCardNumber[j]/10 + digitalCardNumber[j]%10;
    }
    for(int k = 1; k <= totalDigital; k = k + 2){
        sum = sum + digitalCardNumber[k];
    }
    if(sum%10 == 0){
        return 1;
    }else{
        return 0;
    }
    
}
int main() {
    long long cardNum;
    int digitalCardNumber[17];
    int totalDigital;
    cin >> cardNum;
    if (( 999999999999 < cardNum) && (cardNum < 10000000000000)){
        cout << "看來你不是憨包(13位數)";
        totalDigital = 13;
    }else if(( 99999999999999 < cardNum) && ( cardNum < 1000000000000000)){
        cout << "真滴有錢，可是天知道你是不是騙人(15位數)";
        totalDigital = 15;
    }else if(( 999999999999999 < cardNum ) && ( cardNum < 10000000000000000)){
        cout << "恭喜通過第一關(16位數)\n" ;
        totalDigital = 16;
    }else{
        cout << "錯誤誤誤誤誤誤誤誤誤誤誤!!!!!!!";
        return 1;
    }      
    for(int i = 1; i <= totalDigital; i++){
        digitalCardNumber[i] = cardNum%10;
        //cout << digitalCardNumber[i];
        cardNum = cardNum/10;
    }


    if(isVisa(digitalCardNumber,totalDigital)==1){
        if(caculate(digitalCardNumber, totalDigital)==1){
            cout << "100000%是正確的Visa";
        }else{
            cout << "校驗碼錯誤，Visa趕快抱緊處理!!!!!!!";
        }
    }else if(isMaster(digitalCardNumber,totalDigital)==1){
        if(caculate(digitalCardNumber, totalDigital)==1){
            cout << "100000%是正確，Master";
        }else{
            cout << "校驗碼錯誤，Master趕快抱緊處理!!!!!!!";
        }
        caculate(digitalCardNumber, totalDigital);
    }else if(isAE(digitalCardNumber,totalDigital)==1){
        if(caculate(digitalCardNumber, totalDigital)==1){
            cout << "100000%是正確的AE";
        }else{
            cout << "校驗碼錯誤，AE趕快抱緊處理!!!!!!!";
        }
    }else 
        cout << "直接抱緊處理";

}
