// cara run task buat save, compile, dan run rogram press [ctlr + shift + B]

#include <iostream>
#include <string> // string bisa di ganti pakai const char*

using namespace std;


class PersegiPanjang{
    public:

    float y_min ;
    float y_max ;

    float x_min ;
    float x_max ;
    
    //construktor; panjang = vertikal(y), lebar = horizontal(x); object(TP x, TP y, kor. x, kor.y);
    PersegiPanjang(float titikPusat_x, float titikPusat_y, float lebar, float panjang){
        PersegiPanjang::x_min = titikPusat_x - (lebar / 2);
        PersegiPanjang::x_max = titikPusat_x + (lebar / 2);
        
        PersegiPanjang::y_min = titikPusat_y - (panjang / 2);
        PersegiPanjang::y_max = titikPusat_y + (panjang / 2);
        
    }


     //operator overloading ==
    bool operator == (PersegiPanjang object2){
        int irisan_x = 0, irisan_y = 0;
        
        //syarat beririsan pada sumbu Y

        // jika object2 berada disebelah atas
        if(PersegiPanjang::y_max >= object2.y_min && PersegiPanjang::y_min <= object2.y_max){
            irisan_y = 1;
        }
        // jika object2 berada disebelah bawah
        else if ( object2.y_min <= PersegiPanjang::y_max && object2.y_max >= PersegiPanjang::y_min){
            irisan_y = 1;
        }
        
        //syarat beririsan pada sumbu X

        // jika object2 berada disebelah atas
        if(PersegiPanjang::x_max >= object2.y_min && PersegiPanjang::y_min <= object2.x_max){
            irisan_y = 1;
        }
        // jika object2 berada disebelah bawah
        else if ( object2.y_min <= PersegiPanjang::x_max && object2.x_max >= PersegiPanjang::y_min){
            irisan_y = 1;
        }

        //jika beririsan pada sumbu X atau Y
        if (irisan_x == 1 || irisan_y == 1 ) return true;
        return false;
    }



    //operator overloading +
    PersegiPanjang operator + (PersegiPanjang object2){
        
        PersegiPanjang hasil(0,0,0,0);
        
        if(PersegiPanjang::x_max >= object2.x_max){
            hasil.x_max = PersegiPanjang::x_max;
        }else hasil.x_max = object2.x_max;
        
        if(PersegiPanjang::x_min <= object2.x_min){
            hasil.x_min = PersegiPanjang::x_min;
        }else hasil.x_min = object2.x_min;
        
        if(PersegiPanjang::y_max >= object2.y_max){
            hasil.y_max = PersegiPanjang::y_max;
        }else hasil.y_max = object2.y_max;
        
        if(PersegiPanjang::y_min <= object2.y_min){
            hasil.y_min = PersegiPanjang::y_min;
        }else hasil.y_min = object2.y_min;

        


        return hasil;
    }
    
    


    //operator overloading ++
    void operator ++ (){
        
        PersegiPanjang::x_max *= 2;
        PersegiPanjang::x_min *= 2;
        PersegiPanjang::y_max *= 2;
        PersegiPanjang::y_min *= 2;
        
    }

   
   
   //operator overloading -
    PersegiPanjang operator - (PersegiPanjang object2){
        
        PersegiPanjang hasil(0,0,0,0);
        
        if(PersegiPanjang::x_max >= object2.x_max){
            hasil.x_max = object2.x_max;
        }else hasil.x_max = PersegiPanjang::x_max;
        
        if(PersegiPanjang::x_min <= object2.x_min){
            hasil.x_min = object2.x_min;
        }else hasil.x_min = PersegiPanjang::x_min;
        
        if(PersegiPanjang::y_max >= object2.y_max){
            hasil.y_max = object2.y_max;
        }else hasil.y_max = PersegiPanjang::y_max;
        
        if(PersegiPanjang::y_min <= object2.y_min){
            hasil.y_min = object2.y_min;
        }else hasil.y_min = PersegiPanjang::y_min;

        
        return hasil;
    }
    
    
    //operator overloading --
    void operator -- (){
        
        PersegiPanjang::x_max /= 2;
        PersegiPanjang::x_min /= 2;
        PersegiPanjang::y_max /= 2;
        PersegiPanjang::y_min /= 2;
        
    }


    //Fungsi lain2
    void printData(int persegiKe){
        if (persegiKe !=3)
        {
        cout << "\n\nkordinat y persegi ke " << persegiKe << " adalah: "<< PersegiPanjang::y_min
            << " sampai: " << PersegiPanjang::y_max << endl;   
       
        cout << "kordinat x persegi ke " << persegiKe << " adalah: "<< PersegiPanjang::x_min
            << " sampai: " << PersegiPanjang::x_max <<"\n\n"<< endl;   
        }
        else
        {
        cout << "\n\nkordinat y persegi hasil adalah: "<< PersegiPanjang::y_min
             << " sampai: " << PersegiPanjang::y_max << endl;   

        cout << "kordinat x persegi hasil adalah: "<< PersegiPanjang::x_min
            << " sampai: " << PersegiPanjang::x_max <<"\n\n"<< endl;   
        }
    }


};



int main(){


    PersegiPanjang object1(0,0,2,2), object2(0,0,2,2), hasil(0,0,0,0); //object(TP x, TP y, kor. x, kor.y)

    //print data yg sudah di input
    object1.printData(1);
    object2.printData(2);
    
    
    //jika sama maka akan di eksekusi
    while (object1 == object2)
    {
        cout << "object1 dan object2 beririsan!!!" << endl;
        int num;
        cout << "============\nMENU\n============" << endl;
        cout << "1. gabungkan persegi 1 & persegi 2 (operator +)" << endl;
        cout << "2. iriskan persegi 1 & persegi 2 (operator -)" << endl;
        cout << "3. perbesar persegi 1  (operator ++)" << endl;
        cout << "4. perbesar persegi 2  (operator ++)" << endl;
        cout << "5. perkecil persegi 1  (operator --)" << endl;
        cout << "6. perkecil persegi 2  (operator --)" << endl;
        cout << "7. exit program" << endl;
        cout << "PILIHAN ANDA: " << endl;
        cin >> num;
        

        switch (num)
        {
        case 1:
            //memanggil operator overload +
            hasil = object1 + object2;
            hasil.printData(3);
            break;
            
        case 2:
            //memanggil operator overload -
            hasil = object1 - object2;
            hasil.printData(3);
            break;
        
        case 3:
             //memanggil operator overload ++
             ++object1;
            object1.printData(1);
            break;

        case 4:
             //memanggil operator overload ++
             ++object2;
            object2.printData(2);
            break;

        case 5:
             //memanggil operator overload --
             --object1;
            object1.printData(1);
            break;

        case 6:
             //memanggil operator overload --
             --object2;
            object2.printData(2);
            break;
        
        case 7: //exit program
            
            return 0;
        }



       
        
    
    }

    //jika tidak sama 
    cout << "object1 dan object2 tidak beririsan :'(" << endl;
    




    return 0;
}
