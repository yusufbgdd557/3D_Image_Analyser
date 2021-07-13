#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <math.h>
//YUSUF BAÐDAD 180201058 BEKÝR TAÞ 180201092
struct nokta{
    double sayilarx;
    double sayilary;
    double sayilarz;
};
int main()
{
    int i=0,j=-1,k=0,l,boyut;
    char asena[30][50];
    char dodge[20][50];
    DIR *dir;
    struct dirent *yusuf;
    dir=opendir(".");
    if(dir==NULL)
    {
        printf("acilamadi");
        exit(0);
    }
    while((yusuf=readdir(dir))!=NULL)
    {
        strcpy(asena[i],yusuf->d_name);

        boyut=strlen(asena[i]);

        if(asena[i][boyut-4]=='.' && asena[i][boyut-3]=='n' && asena[i][boyut-2]=='k' && asena[i][boyut-1]=='t')
        {
            j++;
            printf("%s\n",asena[i]);
            strcpy(dodge[j],asena[i]);
        }
        i++;
    }
    int secim;
    int frmat;
    int tutan;
    int sat;
    int say=0;
    int a,b,c,e,d=-1,f,g=0;
    int sayilarrgb[3];
    double sayilar[3];
    double d1=0.0,d2=0.0,d3=0.0;
    double enbuyuk,enkucuk,ortalama=0.0;
    double uzaklik=0.0;
    double ortalamatut[j+1];
    double girx,giry,girz,yaricap; //case4 te var
    double x,y,z;
    double minx=100.0,miny=100.0,minz=100.0,maxx=0.0,maxy=0.0,maxz=0.0;
    double kenar;
    char hatasiz[20][50];
    char mazda[4][50];
    char tata[50];
    char atla[10];
    char *p1,*p2,*p3,*p4;
    printf("(1-5)Arasinda Bir Sayi giriniz.(Cikis icin 6)  SECIM:");
    scanf("%d",&secim);
    printf("\n");

    FILE *cikti;

    cikti=fopen("output.txt","w");


    while(secim!=6)
    {
        switch(secim)
        {
        case 1:
            fputs("\nSECIM:1\n",cikti);

            for(k=0; k<=j; k++)
            {
                printf("%s\n",dodge[k]);
                tutan=0;
                sat=0;
                say=0;
                c=0;
                FILE *ptr[k];

                if((ptr[k]=fopen(dodge[k],"r"))!=NULL)
                {
                    while(!feof(ptr[k]))
                    {
                        a=fgetc(ptr[k]);
                        if(a=='\n')
                            say++;
                    }
                    rewind(ptr[k]);
                    say-=5;
                    char chevrolet[5][50];

                    for(tutan=0; tutan<5; tutan++)
                    {
                        fgets(chevrolet[tutan],100,ptr[k]);
                    }
                    for(l=0; l<5; l++)
                    {
                        if(l==1)
                        {
                            p1=strstr(chevrolet[l],"VERSION");
                            if(p1==NULL)
                            {
                                 c=1;
                                 printf("VERSION HATASI\n");
                            }
                        }
                        if(l==2)
                        {
                            p2=strstr(chevrolet[l],"ALANLAR");
                            if(p2==NULL)
                            {
                                c=1;
                                printf("ALANLAR HATASI\n");
                            }
                            if(strstr(chevrolet[l],"x")==NULL || strstr(chevrolet[l],"y")==NULL || strstr(chevrolet[l],"z")==NULL )
                            {
                                c=1;
                                printf("XYZ BILGISI HATASI\n");
                            }
                            if(strstr(chevrolet[l],"x y z r g b")!=NULL && c==0)
                            {
                            for(sat=0; sat<say; sat++)
                                {
                                    fgets(tata,100,ptr[k]);

                                    sayilarrgb[2]=-1;
                                    sscanf(tata,"%lf%lf%lf%d%d%d",&sayilar[0],&sayilar[1],&sayilar[2],&sayilarrgb[0],&sayilarrgb[1],&sayilarrgb[2]);

                                    if(sayilarrgb[2]==-1)
                                    {
                                        c=1;
                                        printf("%d.NOKTADA RGB BILGISI VERILMEMISTIR\n",sat+1);
                                    }
                                }
                            }
                            if(strstr(chevrolet[l],"x y z")!=NULL && strstr(chevrolet[l],"b")==NULL && c==0)
                            {
                                for(sat=0; sat<say; sat++)
                                {
                                    fgets(tata,100,ptr[k]);

                                    sayilar[2]=-1;
                                    sayilarrgb[0]=-1;
                                    sscanf(tata,"%lf%lf%lf%d",&sayilar[0],&sayilar[1],&sayilar[2],&sayilarrgb[0]);

                                    if(sayilar[2]==-1)
                                    {
                                        c=1;
                                        printf("%d.NOKTADA XYZ BILGISI EKSIK\n",sat+1);
                                    }
                                    if(sayilarrgb[0]!=-1)
                                    {
                                        c=1;
                                        printf("%d.NOKTADA RGB HATASI VAR\n",sat+1);
                                    }
                                }
                            }
                        }
                        if(l==3)
                        {
                            p3=strstr(chevrolet[l],"NOKTALAR");

                            if(p3==NULL)
                            {
                                c=1;
                                printf("NOKTALAR BILGISI EKSIK\n");
                            }
                            if(strstr(chevrolet[l+1],"ascii")!=NULL)
                            {
                                sscanf(chevrolet[l],"%s%d",&atla,&b);
                                if(b!=say)
                                {
                                    c=1;
                                    printf("NOKTA SAYISI GECERLI DEGIL\n");
                                }
                            }
                            if(strstr(chevrolet[l+1],"binary")!=NULL)
                            {
                                c=1;
                                printf("okunamadi\n");
                            }

                        }
                        if(l==4)
                        {
                            p4=strstr(chevrolet[l],"DATA");// BURDA DÜZENLEME YAPILACAK
                            if(p4==NULL)
                                c=1;
                        }
                    }
                }
                if(c==0)
                {
                    d++;
                    strcpy(hatasiz[d],dodge[k]);
                }
                printf("\n\n");
                fclose(ptr[k]);
            }
            if(d==j)
            {
                printf("TUM DOSYALAR UYUMLUDUR\n");
                fputs("TUM DOSYALAR UYUMLUDUR\n",cikti);
            }
            else
            {
                printf("UYUMLU DOSYALAR:\n");
                fputs("UYUMLU DOSYALAR:\n",cikti);
            }


            for(int q=0;q<=d;q++)
            {
                printf("%s\n",hatasiz[q]);
                fprintf(cikti,"%s\n",hatasiz[q]);
            }


            break;
        case 2:
            fputs("\nSECIM:2\n",cikti);
            f=d;
            int sayac=0;
            int byknkt1,byknkt2,kcknkt1,kcknkt2;
            for(k=0;k<=d;k++)// d yi yaz
            {
                say=0;
                frmat=0;

                FILE *ptr[k];

                ptr[k]=fopen(hatasiz[k],"r");

                while(!feof(ptr[k]))
                {
                    a=fgetc(ptr[k]);
                    if(a=='\n')
                        say++;
                }
                rewind(ptr[k]);

                say-=5;
                struct nokta karsilastir[say];
                printf("%s\n",hatasiz[k]);
                fprintf(cikti,"%s\n",hatasiz[k]);
                while(frmat<5)
                {
                    a=fgetc(ptr[k]);
                    if(a=='\n')
                        frmat++;
                }
                for(e=0;e<say;e++)
                {
                    fgets(tata,100,ptr[k]);
                    sscanf(tata,"%lf %lf %lf",&karsilastir[e].sayilarx,&karsilastir[e].sayilary,&karsilastir[e].sayilarz);
                }
                rewind(ptr[k]);
                d1 = pow((karsilastir[0].sayilarx-karsilastir[1].sayilarx),2);
                d2 = pow((karsilastir[0].sayilary-karsilastir[1].sayilary),2);
                d3 = pow((karsilastir[0].sayilarz-karsilastir[1].sayilarz),2);
                uzaklik = sqrt(d1+d2+d3);

                enbuyuk=uzaklik;
                enkucuk=uzaklik;

                for(e=0;e<say;e++)
                {
                    for(sat=e+1;sat<say;sat++)
                    {
                        d1 = pow((karsilastir[e].sayilarx-karsilastir[sat].sayilarx),2);
                        d2 = pow((karsilastir[e].sayilary-karsilastir[sat].sayilary),2);
                        d3 = pow((karsilastir[e].sayilarz-karsilastir[sat].sayilarz),2);
                        uzaklik = sqrt(d1+d2+d3);

                        if(enbuyuk<uzaklik)
                        {
                            enbuyuk=uzaklik;
                            byknkt1=e+1;
                            byknkt2=sat+1;
                        }
                        if(enkucuk>uzaklik)
                        {
                            enkucuk=uzaklik;
                            kcknkt1=e+1;
                            kcknkt2=sat+1;
                        }
                        if(ortalama!=0.0)
                            ortalama=(ortalama+uzaklik)/2;
                        else
                            ortalama=uzaklik;
                    }
                }
                ortalamatut[k]=ortalama;
                while(!feof(ptr[k]))
                {
                    sayac++;
                    fgets(tata,100,ptr[k]);

                    if(sayac-5==byknkt1)
                        strcpy(mazda[0],tata);
                    if(sayac-5==byknkt2)
                        strcpy(mazda[1],tata);
                    if(sayac-5==kcknkt2)
                        strcpy(mazda[2],tata);
                    if(sayac-5==kcknkt1)
                        strcpy(mazda[3],tata);
                }
                // En buyuk nokta bilgileri
                printf("En Buyuk Uzaklik %d.Nokta ile %d.Nokta Arasinda\n",byknkt1,byknkt2);
                printf("%s",mazda[0]);
                printf("%s",mazda[1]);
                printf("Mesafe: %lf\n\n",enbuyuk);

                //En kucuk nokta bilgileri
                printf("En Kucuk Uzaklik %d.Nokta ile %d.Nokta Arasinda\n",kcknkt1,kcknkt2);
                printf("%s",mazda[2]);
                printf("%s",mazda[3]);
                printf("Mesafe: %lf\n\n",enkucuk);
                fclose(ptr[k]);
                //dosyaya yazma
                fprintf(cikti,"En Buyuk Uzaklik %d.Nokta ile %d.Nokta Arasinda\n",byknkt1,byknkt2);
                fprintf(cikti,"%s",mazda[0]);
                fprintf(cikti,"%s",mazda[1]);
                fprintf(cikti,"Mesafe: %lf\n\n",enbuyuk);
                fprintf(cikti,"En Kucuk Uzaklik %d.Nokta ile %d.Nokta Arasinda\n",kcknkt1,kcknkt2);
                fprintf(cikti,"%s",mazda[2]);
                fprintf(cikti,"%s",mazda[3]);
                fprintf(cikti,"Mesafe: %lf\n\n",enkucuk);

            }

            break;
        case 3:
            fputs("SECIM:3\n",cikti);

            for(k=0;k<=d;k++)
            {
                FILE *ptr[k];
                frmat=0;

                ptr[k]=fopen(hatasiz[k],"r");

                printf("%s Dosyasinda \nTum Noktalari Kapsayan Kupun Koseleri:\n",hatasiz[k]);
                fprintf(cikti,"%s\nTum Noktalari Kapsayan Kupun Koseleri:\n",hatasiz[k]);

                while(frmat<5)
                    {
                        a=fgetc(ptr[k]);
                        if(a=='\n')
                            frmat++;
                    }

                while(!feof(ptr[k]))
                {
                    sayac++;
                    fgets(tata,100,ptr[k]);
                    sscanf(tata,"%lf %lf %lf",&x,&y,&z);

                        if(minx>x)
                            minx=x;
                        if(miny>y)
                            miny=y;
                        if(minz>z)
                            minz=z;
                        if(maxx<x)
                            maxx=x;
                        if(maxy<y)
                            maxy=y;
                        if(maxz<z)
                            maxz=z;
                }

                    if((maxx-minx)>(maxy-miny)&&(maxx-minx)>(maxz-minz))
                        kenar=(maxx-minx);
                    if((maxy-miny)>(maxx-minx)&&(maxy-miny)>(maxz-minz))
                        kenar=(maxy-miny);
                    if((maxz-minz)>(maxy-miny)&&(maxz-minz)>(maxx-minx))
                        kenar=(maxz-minz);

                printf("%lf %lf %lf \n",(minx+kenar),miny,minz);
                printf("%lf %lf %lf \n",(minx+kenar),miny,(minz+kenar));
                printf("%lf %lf %lf \n",(minx+kenar),(miny+kenar),minz);
                printf("%lf %lf %lf \n",(minx+kenar),(miny+kenar),(minz+kenar));

                printf("%lf %lf %lf \n",minx,miny,minz);
                printf("%lf %lf %lf \n",minx,miny,(minz+kenar));
                printf("%lf %lf %lf \n",minx,(miny+kenar),minz);
                printf("%lf %lf %lf \n\n",minx,(miny+kenar),(minz+kenar));
                fclose(ptr[k]);
                //dosyaya yazdýrma
                fprintf(cikti,"%lf %lf %lf \n",(minx+kenar),miny,minz);
                fprintf(cikti,"%lf %lf %lf \n",(minx+kenar),miny,(minz+kenar));
                fprintf(cikti,"%lf %lf %lf \n",(minx+kenar),(miny+kenar),minz);
                fprintf(cikti,"%lf %lf %lf \n",(minx+kenar),(miny+kenar),(minz+kenar));
                fprintf(cikti,"%lf %lf %lf \n",minx,miny,minz);
                fprintf(cikti,"%lf %lf %lf \n",minx,miny,(minz+kenar));
                fprintf(cikti,"%lf %lf %lf \n",minx,(miny+kenar),minz);
                fprintf(cikti,"%lf %lf %lf \n\n",minx,(miny+kenar),(minz+kenar));
            }

            break;
        case 4:
                fputs("\nSECIM:4\n",cikti);

                printf("Kurenin Merkezinin X Y Z Koordinatlarini Giriniz\n");
                printf("x:");
                scanf("%lf",&girx);
                printf("y:");
                scanf("%lf",&giry);
                printf("z:");
                scanf("%lf",&girz);
                printf("Yaricapi Giriniz:");
                scanf("%lf",&yaricap);
            for(k=0;k<=d;k++)
            {
                FILE *ptr[k];

                ptr[k]=fopen(hatasiz[k],"r");


                printf("%s Dosyasinda\nVerilen Kurenin Icinde Bulunan Tum Noktalar:\n",hatasiz[k]);
                fprintf(cikti,"%s\n\nVerilen Kurenin Icinde Bulunan Tum Noktalar:\n",hatasiz[k]);
                fprintf(cikti,"%s\n\nVerilen Kurenin Icinde Bulunan Tum Noktalar:\n",hatasiz[k]);


                while(frmat<5)
                    {
                        a=fgetc(ptr[k]);
                        if(a=='\n')
                            frmat++;
                    }

                while(!feof(ptr[k]))
                {
                    fgets(tata,100,ptr[k]);
                    sscanf(tata,"%lf %lf %lf",&x,&y,&z);
                    //printf("%s",tata);
                    d1 = pow((girx-x),2);
                    d2 = pow((giry-y),2);
                    d3 = pow((girz-z),2);
                    uzaklik = sqrt(d1+d2+d3);

                    if(uzaklik<yaricap)
                    {
                        g++;
                        printf("%d) %s",g,tata);
                        fprintf(cikti,"%d) %s",g,tata);
                    }
                }
                g=0;
                printf("\n");
                fclose(ptr[k]);
            }

            break;
        case 5:
            fputs("\nSECIM:5\n",cikti);

            for(k=0;k<=d;k++) //f yi koy
            {
                printf("%s dosyasinin ",hatasiz[k]);
                printf("ortalamasi:%lf\n",ortalamatut[k]);
                fprintf(cikti,"%s dosyasinin ",hatasiz[k]);
                fprintf(cikti,"ortalamasi:%lf\n",ortalamatut[k]);
            }
            break;
        }
        if(5<secim||secim<1)
            printf("yanlis bir deger girdiniz.");

        printf("\n(1-5)Arasinda Bir Sayi giriniz.(Cikis icin 6)  SECIM:");
        scanf("%d",&secim);
    }
    fclose(cikti);
    return 0;
}
