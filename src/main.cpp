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

    float getPanjang(){

        float panjang;
        panjang = PersegiPanjang::y_max - PersegiPanjang::y_min;

        return panjang;
    }

    float getLebar(){

        float lebar;
        lebar = PersegiPanjang::x_max - PersegiPanjang::x_min;
        
        return lebar;
    }
    

};


// kartesius 1 object
class Kartesius_1_object{
    public:

    float map_x ; //jumlah x positif
    float map_y ; //jumlah y positif


   float shape_1_y_min ;
   float shape_1_y_max ;
   float shape_1_x_min ;
   float shape_1_x_max ;


    Kartesius_1_object(PersegiPanjang persegi_1){

        Kartesius_1_object::shape_1_y_min = persegi_1.y_min;
        Kartesius_1_object::shape_1_y_max = persegi_1.y_max;

        Kartesius_1_object::shape_1_x_min = persegi_1.x_min;
        Kartesius_1_object::shape_1_x_max = persegi_1.x_max;

        if(persegi_1.x_max > (-persegi_1.x_min)){
            Kartesius_1_object::map_x = persegi_1.x_max;
            }else Kartesius_1_object::map_x = (-persegi_1.x_min);
        
         if(persegi_1.y_max > (-persegi_1.y_min)){
            Kartesius_1_object::map_y = persegi_1.y_max;
            }else Kartesius_1_object::map_y = (-persegi_1.y_min);

    }

    void drawMap(){
        
        float n_map_y = Kartesius_1_object::map_y, n_map_x = Kartesius_1_object::map_x ;
        int counter_x = 0, counter_y = 0;

        for(int i = map_y ; i >= (- map_y);i--){ //buat sumbu y


            for(int u = - map_x; u <= (map_x);u++){ // buat sumbu x
                
                //print angka sumbu y
                if(u == 0) {
                    if((n_map_y - counter_y) >= 0) cout << " ";
                    cout<< n_map_y - counter_y;
                 
                 //print angka sumbu x
                 }else if(i == 0){
                 
                    if((counter_x - n_map_x) >=0) cout << " ";
                    cout<< counter_x - n_map_x ;
                 
                 //print atas shape 1
                 } else if(i == shape_1_y_max && (shape_1_x_min <= u && shape_1_x_max >=u)  ){
                     cout<< " ." ;
                //print bawah shape 1
                 }else if(i == shape_1_y_min && (shape_1_x_min <= u && shape_1_x_max >=u)  ){
                     cout<< " ." ;
                //print kiri shape 1
                 }else if(u == shape_1_x_min && (shape_1_y_min <= i && shape_1_y_max >=i)  ){
                     cout<< " ." ;
                //print kanan shape 1
                 }else if(u == shape_1_x_max && (shape_1_y_min <= i && shape_1_y_max >=i)  ){
                     cout<< " ." ;
                //print ruang kosong
                 }else cout<< "  " ; 



                counter_x++;
            }
            counter_x =0;
            counter_y++;
            cout<< endl;
        }
        cout <<"\nNOTE:\n";
        cout <<"jika panjang/lebar di bagi 2 = bilangan bulat, map akan tergambar seluruhnya\n";
        cout <<"jika panjang/lebar di bagi 2 = 0.5, map akan menggambar titik2nya saja\n";
        cout <<"jika panjang/lebar di bagi 2 = 0.25/0.75, map akan menggambar sumbunya saja\n\n\n";
    }

};


// kartesius 2 object
class Kartesius_2_object{
    public:

    float map_x ; //jumlah x positif
    float map_y ; //jumlah y positif


   float shape_1_y_min ;
   float shape_1_y_max ;
   float shape_1_x_min ;
   float shape_1_x_max ;
   float shape_2_y_min ;
   float shape_2_y_max ;
   float shape_2_x_min ;
   float shape_2_x_max ;

    Kartesius_2_object(PersegiPanjang persegi_1, PersegiPanjang persegi_2 ){


        Kartesius_2_object::shape_1_y_min = persegi_1.y_min;
        Kartesius_2_object::shape_1_y_max = persegi_1.y_max;

        Kartesius_2_object::shape_1_x_min = persegi_1.x_min;
        Kartesius_2_object::shape_1_x_max = persegi_1.x_max;

        Kartesius_2_object::shape_2_y_min = persegi_2.y_min;
        Kartesius_2_object::shape_2_y_max = persegi_2.y_max;

        Kartesius_2_object::shape_2_x_min = persegi_2.x_min;
        Kartesius_2_object::shape_2_x_max = persegi_2.x_max;

        // mencari panjang x maksimal
        if(persegi_1.x_max > (-persegi_1.x_min)){
            Kartesius_2_object::map_x = persegi_1.x_max;
            }else Kartesius_2_object::map_x = (-persegi_1.x_min);
        
        if(Kartesius_2_object::map_x < persegi_2.x_max){
            Kartesius_2_object::map_x = persegi_2.x_max;
            }
        if(Kartesius_2_object::map_x < (-persegi_2.x_min)){
            Kartesius_2_object::map_x = (-persegi_2.x_min);
            }
        
        // mencari panjang y maksimal
        if(persegi_1.y_max > (-persegi_1.y_min)){
            Kartesius_2_object::map_y = persegi_1.y_max;
            }else Kartesius_2_object::map_y = (-persegi_1.y_min);
        
        if(Kartesius_2_object::map_y < persegi_2.y_max){
            Kartesius_2_object::map_y = persegi_2.y_max;
            }
        if(Kartesius_2_object::map_y < (-persegi_2.y_min)){
            Kartesius_2_object::map_y = (-persegi_2.y_min);
            }



    }

    void drawMap(){
        
        float n_map_y = Kartesius_2_object::map_y, n_map_x = Kartesius_2_object::map_x ;
        float counter_x = 0, counter_y = 0;

        for(float i = map_y ; i >= (- map_y);i--){ //buat sumbu y


            for(float u = - map_x; u <= (map_x);u++){ // buat sumbu x
                
                //print angka sumbu y
                if(u == 0) {
                    if((n_map_y - counter_y) >= 0) cout << " ";
                    cout<< n_map_y - counter_y;
                 
                 //print angka sumbu x
                 }else if(i == 0){
                 
                    if((counter_x - n_map_x) >=0) cout << " ";
                    cout<< counter_x - n_map_x ;
                 
                 //print atas shape 1
                 } else if(i == shape_1_y_max && (shape_1_x_min <= u && shape_1_x_max >=u)  ){
                     cout<< " ." ;
                //print bawah shape 1
                 }else if(i == shape_1_y_min && (shape_1_x_min <= u && shape_1_x_max >=u)  ){
                     cout<< " ." ;
                //print kiri shape 1
                 }else if(u == shape_1_x_min && (shape_1_y_min <= i && shape_1_y_max >=i)  ){
                     cout<< " ." ;
                //print kanan shape 1
                 }else if(u == shape_1_x_max && (shape_1_y_min <= i && shape_1_y_max >=i)  ){
                     cout<< " ." ;
                //print atas shape 2
                 }else if(i == shape_2_y_max && (shape_2_x_min <= u && shape_2_x_max >=u)  ){
                     cout<< " ." ;
                //print bawah shape 2
                 }else if(i == shape_2_y_min && (shape_2_x_min <= u && shape_2_x_max >=u)  ){
                     cout<< " ." ;
                //print kiri shape 2
                 }else if(u == shape_2_x_min && (shape_2_y_min <= i && shape_2_y_max >=i)  ){
                     cout<< " ." ;
                //print kanan shape 2
                 }else if(u == shape_2_x_max && (shape_2_y_min <= i && shape_2_y_max >=i)  ){
                     cout<< " ." ;
                 }else cout<< "  " ; //print ruang kosong



                counter_x++;
            }
            counter_x =0;
            counter_y++;
            cout<< endl;
        }
    
        cout <<"\nNOTE:\n";
        cout <<"jika panjang/lebar di bagi 2 = bilangan bulat, map akan tergambar seluruhnya\n";
        cout <<"jika panjang/lebar di bagi 2 = 0.5, map akan menggambar titik2nya saja\n";
        cout <<"jika panjang/lebar di bagi 2 = 0.25/0.75, map akan menggambar sumbunya saja\n\n\n";
    }

};







int main(){
    cout << "Program ini adalah hasil original M Fathi Farhat 5024211065. \nDiperbolehkan menjadi sumber referensi namun dilarang keras mengcopy tanpa seizin pemilik"<<endl;

    //var. input shape 1
    float shape_1_TP_X, shape_1_TP_y, shape_1_panjang, shape_1_lebar;
    //var. input shape 2
    float shape_2_TP_X, shape_2_TP_y, shape_2_panjang, shape_2_lebar;


    inputHere:
    //input shape 1
    cout << endl <<"=============\nData Persegi 1\n============= ";
    cout <<"\nSaran: masukan bilangan genap\n";
    cout << endl <<"Masukan Titik Pusat X Persegi 1: ";
    cin >> shape_1_TP_X;
    cout << endl <<"Masukan Titik Pusat Y Persegi 1: ";
    cin >> shape_1_TP_y;
    cout << endl <<"Masukan Panjang Persegi 1: ";
    cin >> shape_1_panjang;
    cout << endl <<"Masukan Leabr Persegi 1: ";
    cin >> shape_1_lebar;
    
    //input shape 2
    cout << endl <<"=============\nData Persegi 2\n============= ";
    cout <<"\nSaran: masukan bilangan genap\n";
    cout << endl <<"Masukan Titik Pusat X Persegi 2: ";
    cin >> shape_2_TP_X;
    cout << endl <<"Masukan Titik Pusat Y Persegi 2: ";
    cin >> shape_2_TP_y;
    cout << endl <<"Masukan Panjang Persegi 2: ";
    cin >> shape_2_panjang;
    cout << endl <<"Masukan Leabr Persegi 2: ";
    cin >> shape_2_lebar;




    PersegiPanjang object1(shape_1_TP_X,shape_1_TP_y,shape_1_lebar,shape_1_panjang); 
    PersegiPanjang object2(shape_2_TP_X,shape_2_TP_y,shape_2_lebar,shape_2_panjang); 
    PersegiPanjang hasil(0,0,0,0); //object(TP x, TP y, kor. x, kor.y)


    cekInput:
    //print data yg sudah di input
    object1.printData(1);
    object2.printData(2);
    
 
    Kartesius_1_object map_1(hasil);

    Kartesius_2_object map_2(object1, object2);
    map_2.drawMap();





    //jika sama maka akan di eksekusi
    while (object1 == object2)
    {
        Kartesius_1_object map_1(hasil);

        cout << "object1 dan object2 beririsan!!!" << endl;
        int num;
        cout << "============\nMENU\n============" << endl;
        cout << "1. gabungkan persegi 1 & persegi 2 (operator +)" << endl;
        cout << "2. iriskan persegi 1 & persegi 2 (operator -)" << endl;
        cout << "3. perbesar persegi 1  (operator ++)" << endl;
        cout << "4. perbesar persegi 2  (operator ++)" << endl;
        cout << "5. perkecil persegi 1  (operator --)" << endl;
        cout << "6. perkecil persegi 2  (operator --)" << endl;
        cout << "7. cek irisan  (operator ==)" << endl;
        cout << "8. input ulang data" << endl;
        cout << "9. exit program" << endl;
        cout << "PILIHAN ANDA: " << endl;
        cin >> num;
        

        switch (num)
        {
        case 1:
            //memanggil operator overload +
            hasil = object1 + object2;
            hasil.printData(3);
            map_1 = hasil;
            map_1.drawMap();
            break;
            
        case 2:
            //memanggil operator overload -
            hasil = object1 - object2;
            hasil.printData(3);
            map_1 = hasil;
            map_1.drawMap();
            break;
        
        case 3:
             //memanggil operator overload ++
             ++object1;
            object1.printData(1);
            map_1 = object1;
            map_1.drawMap();
            break;

        case 4:
             //memanggil operator overload ++
             ++object2;
            object2.printData(2);
            map_1 = object2;
            map_1.drawMap();
            break;

        case 5:
             //memanggil operator overload --
             --object1;
            object1.printData(1);
            map_1 = object1;
            map_1.drawMap();
            break;

        case 6:
             //memanggil operator overload --
             --object2;
            object2.printData(2);
            map_1 = object2;
            map_1.drawMap();
            break;
        
        case 7:
             //memanggil operator overload -- yg sudah di pakai di awal
            goto cekInput;
            break;
        
        case 8:
             //input kembali ke awal
            goto inputHere;
            break;
       
        case 9: //exit program
            
            return 0;
        }



       
        
    
    }

    //jika tidak sama 
    cout << "persegi 1 dan persegi 2 tidak beririsan :'(" << endl;
    




    return 0;
}
