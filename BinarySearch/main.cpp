#include <iostream>
using namespace std;

void merge(int arr[], int const basla, int const orta, int const son) { // �ki alt diziyi birle�tiren fonksiyon
    int const altdizi1 = orta - basla + 1; // Alt dizilerin boyutlar�n� hesaplar.
    int const altdizi2 = son - orta;

    int sol[altdizi1], sag[altdizi2]; // Alt dizileri olu�turur.

    for (int i = 0; i < altdizi1; i++)// Alt dizileri doldurur.
        sol[i] = arr[basla + i];
    for (int j = 0; j < altdizi2; j++)
        sag[j] = arr[orta + 1 + j];

    int i = 0, j = 0, k = basla;  // �lk alt dizinin indisleri i, ikinci alt dizinin indisleri j, ana dizinin indisleri k olarak tan�mlan�r.
    while (i < altdizi1 && j < altdizi2) { // Alt dizileri birle�tirir.
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
    while (i < altdizi1) { // Sol alt dizide eleman kalm��sa kalan elemanlar� ekler.
        arr[k] = sol[i];
        i++;
        k++;
    }
    while (j < altdizi2) { // Sa� alt dizide eleman kalm��sa kalan elemanlar� ekler.
        arr[k] = sag[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int const basla, int const son) // Diziyi ilk par�alara ay�r�p sonra birle�tiren birle�tirme s�ralama (merge sort) algoritmas�
{
    if (basla >= son) // Dizi 1 veya daha az elemana sahipse s�ralanm�� kabul et
        return;
    int orta = basla + (son - basla) / 2;   // Orta noktay� hesaplar
    mergeSort(arr, basla, orta); // �zyineleme yaparak alt dizileri s�ralar.
    mergeSort(arr, orta + 1, son);
    merge(arr, basla, orta, son);  // Alt dizileri birle�tiren fonksiyon
}

int binarySearch(int dizi[], int baslangic, int son, int arananDeger) { // �kili arama algoritmas�
    while (baslangic <= son) {
        int orta = baslangic + (son - baslangic) / 2;

        if (dizi[orta] == arananDeger) // Orta noktadaki de�er aranan de�er ise orta noktan�n indisini d�nd�r�r.
            return orta;

        if (dizi[orta] > arananDeger)  // Orta noktadaki de�er aranan de�erden b�y�kse sol tarafta arama yapar.
            son = orta - 1;
        else  // Orta noktadaki de�er aranan de�erden k���kse sa� tarafta arama yapar.
            baslangic = orta + 1;
    }
    return -1;  // E�er aranan de�er dizi i�inde yoksa -1 d�nd�r�l�r.
}

int main()
{
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68}; // KUllan�lacak dizi
    int x = sizeof(dizi) / sizeof(dizi[0]); // Dizinin boyutunu hesaplar.
    int arananeleman; // Aranan eleman� tutacak de�i�ken
    cout << "Dizide aramis oldugunuz degeri giriniz:";
    cin >> arananeleman;

    mergeSort(dizi, 0, x - 1); // Dizi mergeSort fonksiyonu i�erisine g�nderilerek s�ralan�r.
    int sonuc = binarySearch(dizi, 0, x - 1, arananeleman); // S�ral� dizide binary search algoritmas�n� kullanarak aranacak eleman�n indisi bulunur.
    if (sonuc == -1)  // E�er aranan eleman dizide yoksa -1 d�ner ve bunu kontrol ederek kullan�c�ya mesaj verir.
        cout << "Aranan eleman dizide bulunamadi.\n";
    else
        cout << "Aranan eleman " << sonuc << ". indiste bulundu.\n";  // Aranan eleman dizide varsa bulundu�u indisi ekrana yazd�r�r.

    return 0;
}



