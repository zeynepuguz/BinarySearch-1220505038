#include <iostream>
using namespace std;

void merge(int arr[], int const basla, int const orta, int const son) { // Ýki alt diziyi birleþtiren fonksiyon
    int const altdizi1 = orta - basla + 1; // Alt dizilerin boyutlarýný hesaplar.
    int const altdizi2 = son - orta;

    int sol[altdizi1], sag[altdizi2]; // Alt dizileri oluþturur.

    for (int i = 0; i < altdizi1; i++)// Alt dizileri doldurur.
        sol[i] = arr[basla + i];
    for (int j = 0; j < altdizi2; j++)
        sag[j] = arr[orta + 1 + j];

    int i = 0, j = 0, k = basla;  // Ýlk alt dizinin indisleri i, ikinci alt dizinin indisleri j, ana dizinin indisleri k olarak tanýmlanýr.
    while (i < altdizi1 && j < altdizi2) { // Alt dizileri birleþtirir.
        if (sol[i] <= sag[j]) {
            arr[k] = sol[i];
            i++;
        }
        else {
            arr[k] = sag[j];
            j++;
        }
        k++;
    }
    while (i < altdizi1) { // Sol alt dizide eleman kalmýþsa kalan elemanlarý ekler.
        arr[k] = sol[i];
        i++;
        k++;
    }
    while (j < altdizi2) { // Sað alt dizide eleman kalmýþsa kalan elemanlarý ekler.
        arr[k] = sag[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int const basla, int const son) // Diziyi ilk parçalara ayýrýp sonra birleþtiren birleþtirme sýralama (merge sort) algoritmasý
{
    if (basla >= son) // Dizi 1 veya daha az elemana sahipse sýralanmýþ kabul et
        return;
    int orta = basla + (son - basla) / 2;   // Orta noktayý hesaplar
    mergeSort(arr, basla, orta); // Özyineleme yaparak alt dizileri sýralar.
    mergeSort(arr, orta + 1, son);
    merge(arr, basla, orta, son);  // Alt dizileri birleþtiren fonksiyon
}

int binarySearch(int dizi[], int baslangic, int son, int arananDeger) { // Ýkili arama algoritmasý
    while (baslangic <= son) {
        int orta = baslangic + (son - baslangic) / 2;

        if (dizi[orta] == arananDeger) // Orta noktadaki deðer aranan deðer ise orta noktanýn indisini döndürür.
            return orta;

        if (dizi[orta] > arananDeger)  // Orta noktadaki deðer aranan deðerden büyükse sol tarafta arama yapar.
            son = orta - 1;
        else  // Orta noktadaki deðer aranan deðerden küçükse sað tarafta arama yapar.
            baslangic = orta + 1;
    }
    return -1;  // Eðer aranan deðer dizi içinde yoksa -1 döndürülür.
}

int main()
{
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68}; // KUllanýlacak dizi
    int x = sizeof(dizi) / sizeof(dizi[0]); // Dizinin boyutunu hesaplar.
    int arananeleman; // Aranan elemaný tutacak deðiþken
    cout << "Dizide aramis oldugunuz degeri giriniz:";
    cin >> arananeleman;

    mergeSort(dizi, 0, x - 1); // Dizi mergeSort fonksiyonu içerisine gönderilerek sýralanýr.
    int sonuc = binarySearch(dizi, 0, x - 1, arananeleman); // Sýralý dizide binary search algoritmasýný kullanarak aranacak elemanýn indisi bulunur.
    if (sonuc == -1)  // Eðer aranan eleman dizide yoksa -1 döner ve bunu kontrol ederek kullanýcýya mesaj verir.
        cout << "Aranan eleman dizide bulunamadi.\n";
    else
        cout << "Aranan eleman " << sonuc << ". indiste bulundu.\n";  // Aranan eleman dizide varsa bulunduðu indisi ekrana yazdýrýr.

    return 0;
}



