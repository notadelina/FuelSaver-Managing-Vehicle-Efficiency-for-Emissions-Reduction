#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;

class Car {
    public :
    string mBrand;
    string mLicensePlate;
    uint16_t mYearOfFabrication;
    double mAverageConsumption;
    uint32_t mNumberOfKilometers;

    Car(string brand, string license, uint16_t year, double consumption, uint32_t km) {
        mBrand = brand;
        mLicensePlate = license;
        mYearOfFabrication = year;
        mAverageConsumption = consumption;
        mNumberOfKilometers = km;
    }
    Car()
    {
         mBrand = "";
        mLicensePlate = "";
        mYearOfFabrication = 0;
        mAverageConsumption = 0;
        mNumberOfKilometers = 0;
    }
    string getBrand() const{
        return mBrand;
    }

    string getLicensePlate() const {
        return mLicensePlate;
    }

    uint16_t getYearOfFabrication() const
    {
        return mYearOfFabrication;
    }

    double getAverageConsumption()
    {
        return mAverageConsumption;
    }

    uint32_t getNumberOfKilometers()
    {
        return mNumberOfKilometers;
    }

    virtual double getFuelConsumption() const = 0;
    virtual double getFuelCost()const = 0;
    virtual string getType() const = 0;

    bool operator < (const Car & A)
    {
        if(mYearOfFabrication != A.mYearOfFabrication)
           return mYearOfFabrication < A.mYearOfFabrication;
        else
        {
            if(mNumberOfKilometers != A.mNumberOfKilometers)
              return mNumberOfKilometers < A.mNumberOfKilometers;

             else
             {
                 if(mAverageConsumption != A.mAverageConsumption)
                return mAverageConsumption < A.mAverageConsumption;
             }
        }
    }



};
class PetrolCar : public  Car
{
   public :
   PetrolCar(string brand, string license, uint16_t year, double consumption, uint32_t km) : Car( brand, license,  year, consumption,  km)
   {

   }
    double getFuelConsumption() const
    {
         return ((0.879 *mAverageConsumption * mNumberOfKilometers) / 100);
    }

    double getFuelCost() const
    {
        return getFuelConsumption() * 4.5;
    }
    string getType() const
    {
        return "benzina";
    }


};

class DieselCar : public Car
{

    public:
    DieselCar(string brand, string license, uint16_t year, double consumption, uint32_t km) : Car( brand, license,  year, consumption,  km)
    {}

    double getFuelConsumption() const
    {
         return (0.789 *mAverageConsumption * mNumberOfKilometers) / 100;
    }

    double getFuelCost() const
    {
        return getFuelConsumption() * 4.8;
    }
    string getType() const
    {
        return "diesel";
    }


};

class HybridCar : public Car
{


    public:
    HybridCar(string brand, string license, uint16_t year, double consumption, uint32_t km) : Car( brand, license,  year, consumption,  km)
    {}

    double getFuelConsumption() const
    {
         return (mAverageConsumption * mNumberOfKilometers - 0.124 * mNumberOfKilometers) / 100;
    }

    double getFuelCost() const
    {
        return getFuelConsumption() * 4.5;
    }
    string getType() const
    {
        return "hibrid";
    }
};


class ElectricCar : public Car
 {
      public:
    ElectricCar(string brand, string license, uint16_t year, double consumption, uint32_t km) : Car( brand, license,  year, consumption,  km)
    {}

    double getFuelConsumption() const
    {
         return 0;
    }

    double getFuelCost() const
    {
        return 0;
    }
    string getType() const
    {
        return "electrica";
    }

};

static bool sortare ( Car *A,   Car *B)
{
   if(A->getYearOfFabrication() != B->getYearOfFabrication())
           return A->getYearOfFabrication() > B->getYearOfFabrication();
        else
        {
            if(A->getNumberOfKilometers() != B->getNumberOfKilometers())
              return A->getNumberOfKilometers() < B->getNumberOfKilometers();

             else
             {

                return A->getAverageConsumption() > B->getAverageConsumption();
             }
        }
}

bool verificare(string placuta)
{
    if(placuta.size()==6)
    {
        if(isupper(placuta[0]) && isdigit(placuta[1]) && isdigit(placuta[2]) && isupper(placuta[3]) && isupper(placuta[4]) && isupper(placuta[5]))
            return true;
            else
            return false;
    }
    if(placuta.size()==7)
        {
            if(isdigit(placuta[1]))
            {
                if(isupper(placuta[0]) && isdigit(placuta[1]) && isdigit(placuta[2]) && isdigit(placuta[3]) && isupper(placuta[4]) && isupper(placuta[5]) && isupper(placuta[6]))
                    return true;
                    else
                    return false;
            }
            else
            if(!isdigit(placuta[1]))
            {
               if(isupper(placuta[0]) && isupper(placuta[1]) && isdigit(placuta[2]) && isdigit(placuta[3]) && isupper(placuta[4]) && isupper(placuta[5]) && isupper(placuta[6]))
                    return true;
                    else
                    return false;
            }
        }
    if(placuta.size()==8)
    {
        if(isupper(placuta[0]) && isupper(placuta[1]) && isdigit(placuta[2]) && isdigit(placuta[3]) && isdigit(placuta[4]) && isupper(placuta[5]) && isupper(placuta[6]) && isupper(placuta[7]))
        return true;
        else
        return false;
    }
    else
    return false;
}





int main()
{

    int n;
    string cerinta;
    vector <Car*> masini;
    string type;
    string combustibil;
    string nr_inmatriculare;
    uint16_t an;
    double consum;
    uint32_t km;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>type;
        cin>>combustibil;
        cin>>nr_inmatriculare;
        cin>>an;
        cin>>consum;
        cin>>km;

        if(combustibil == "benzina")
            masini.push_back(new PetrolCar(type,nr_inmatriculare,an,consum,km));

        if(combustibil == "diesel")
            masini.push_back(new DieselCar(type,nr_inmatriculare,an,consum,km));

        if(combustibil == "electrica")
            masini.push_back(new ElectricCar(type,nr_inmatriculare,an,consum,km));

        if(combustibil == "hibrid")
            masini.push_back(new HybridCar(type,nr_inmatriculare,an,consum,km));

    }

    cin>>cerinta;

    if(cerinta == "a")
    {  sort(masini.begin(), masini.end(), sortare);
      for(int i=0;i<n;i++)
      {

          cout<<"Masina "<<masini[i]->getBrand()<<" cu numarul de inmatriculare "<<masini[i]->getLicensePlate()<<" a parcurs "<<masini[i]->getNumberOfKilometers()<<"km si a consumat ";
          printf("%.3lf litri.\n", masini[i]->getFuelConsumption());
      }

    }


    if(cerinta == "b")
    {
        double suma;
        for(int i=0;i<n;i++)
        {
            suma = suma + masini[i]->getFuelCost();
        }
        printf("%.2lf", suma);
    }

    if(cerinta == "c")
    {
        while(cin>>type)
        {
        cin>>combustibil;
        cin>>nr_inmatriculare;
        cin>>an;
        cin>>consum;
        cin>>km;
        n++;
        if(combustibil == "benzina")
            masini.push_back(new PetrolCar(type,nr_inmatriculare,an,consum,km));

        if(combustibil == "diesel")
            masini.push_back(new DieselCar(type,nr_inmatriculare,an,consum,km));

        if(combustibil == "electrica")
            masini.push_back(new ElectricCar(type,nr_inmatriculare,an,consum,km));

        if(combustibil == "hibrid")
            masini.push_back(new HybridCar(type,nr_inmatriculare,an,consum,km));
        }

        uint32_t nr_km = 0;
        double consum_mediu = 0;
        for(int i=0;i<n;i++) {
            nr_km = nr_km + masini[i]->getNumberOfKilometers();
            consum_mediu = consum_mediu + masini[i]->getAverageConsumption();
        }
        cout<<nr_km<<" km"<<endl;
        printf("%.2lf", consum_mediu/n);
        cout<<" L/100km"<<endl;
    }
     if(cerinta == "d")
    {
        int benzina = 0;
        int diesel = 0;
        int electrica = 0;
        int hibrid = 0;
        for(int i=0;i<n;i++)
        {
            if(masini[i]->getType() == "benzina")
                benzina++;
            if(masini[i]->getType() == "diesel")
                diesel++;
            if(masini[i]->getType() == "electrica")
                electrica++;
            if(masini[i]->getType() == "hibrid")
                hibrid++;


        }
        cout<<"benzina -> "<<benzina<<endl;
        cout<<"diesel -> "<<diesel<<endl;
        cout<<"electrica -> "<<electrica<<endl;
        cout<<"hibrid -> "<<hibrid<<endl;

    }




   if(cerinta=="e")
    {
        for(int i=0; i<n; i++)
        {
            if(verificare(masini[i]->getLicensePlate())==false)
            cout<<masini[i]->getLicensePlate()<<":"<<" numar de inmatriculare invalid"<<endl;
        }
    }


    return 0;
}