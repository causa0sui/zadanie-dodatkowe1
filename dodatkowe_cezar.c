#include <stdio.h>
int main()
{
 char text[200];/* cia!g skonczony tekstu rozmiarem do 200 liter */
 char letter; /* Służy do przechowywania i szyfrowania litery tekstu */
 int input_result=-1; /* wynik wyboru */
 int step; /* przesunięcie */
 int index=0; /* indeks ciagu */
 char text_prefix[3]; /* prefiks dla wyświetlenia wyników programu
 /* -------------------- Wybór trybu ---------------------------- */
 while ((input_result!=0)&&(input_result!=1))
 {
  printf ("Kliknij 0 dla szyfrowania lub 1 dla deszyfrowania: ");
  scanf("%d",&input_result);
 }
 switch (input_result)
 {
   case 0:
   {
    step=3;
    text_prefix[0]='z';
    text_prefix[1]='a';
    text_prefix[2]='\0';
    printf ("Wpisz tekst jawny dla szyfrowania: ");
    break;
   }
   case 1:
   {
    step=-3;
    text_prefix[0]='o';
    text_prefix[1]='d';
    text_prefix[2]='\0';
    printf ("Wpisz tekst zaszyfrowany dla deszyfrowania: ");
   }
 }
 scanf("%s",&text);
 /* --------------- szyfrowanie -------------------------------------- */
 while (text[index]!='\0')
 {
  text[index]+=step; /* zmiana kodu ASCII zgodnie z przesunięciem */
   if (text[index]>122) text[index]=96+(text[index]-122);/* cykliczność od "z" do "a" dla szyfrowania */
   else if (text[index]<97) text[index]=123-(97-text[index]);/* cykliczność dla deszyfrowania */
  index++;
 }
 printf ("Tekst %sshyfrowany: %s", text_prefix, text);
 return 0;
}
