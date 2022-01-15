#include<stdio.h>
#include<windows.h>

//ordenacao mergesort

void intercala(int v[],int p,int q,int r)
{
    int i = p,j = q,z,k = 0;
    int w[r-p];
    while(i < q && j < r)
    {
        if(v[i] <= v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while(i < q) w[k++] = v[i++];
    while(j < r) w[k++] = v[j++];
    for(k = 0; k < r-p; k++)
        v[p+k] = w[k];
}
void mergesort (int v[],int p,int r)
{
    int q;
    if(p < r-1)
    {
        q = (p+r)/2;
        mergesort(v,q,r);
        mergesort(v,p,q);
        intercala(v,p,q,r);
    }
}

//ordenacao bolha

void ord_bolha (int aux,int n,int v[])
{
    int i,j;
    for(i = aux; i < n-1; i++)
        for(j =i+1; j < n; j++)
            if(v[i] > v[j])
            {
                int y = v[i];
                v[i] = v[j];
                v[j] = y;
            }
}

//ordenacao por insercao

void insercao (int v[],int n)
{
    int i,j,x;
    for(i = 1; i < n; i++)
    {
        x = v[i];
        for(j = i-1; j >= 0 && v[j] > x; j--)
            v[j+1] = v[j];
        v[j+1] = x;
    }
}

//ordenacao por selecao.

void selecao (int n,int v[])
{
    int i,j,min;
    for(i = 0; i < n-1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
            if(v[min] > v[j])
                min = j;
        int y = v[min];
        v[min] = v[i];
        v[i] = y;
    }
}

//ordenacao heapsort

void faz_heap (int m,int v[])
{
    int f = m+1;
    while(f > 1 && v[f/2] < v[f])
    {
        int r = v[f/2];
        v[f/2] = v[f];
        v[f] = r;
        f /= 2;
    }
}
void SacodeHeap (int m, int v[])
{
    int t, f = 2;
    while (f <= m)
    {
        if (f < m && v[f] < v[f+1]) ++f;
        if (v[f/2] >= v[f]) break;
        t = v[f/2];
        v[f/2] = v[f];
        v[f] = t;
        f *= 2;
    }
}
void Heapsort (int n, int v[])
{
    int m;
    for (m = 1; m < n; m++)
        faz_heap(m,v);
    for (m = n; m > 1; m--)
    {
        int t = v[1];
        v[1] = v[m];
        v[m] = t;
        SacodeHeap (m-1,v);
    }
}

void transforma_vetor (int n,int *v)
{
    int i;
    for(i = n-1; i >= 0; i--)
    {
        v[i+1] = v[i];
    }
}

//ordenacao quicksort.

int separa (int v[],int p,int r)
{
    int pivo = v[r],k,j = p;
    for(k = p; k < r; k++)
    {
        if(v[k] <= pivo)
        {
            int a = v[k];
            v[k] = v[j];
            v[j] = a;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = pivo;
    return j;
}

void quicksort(int v[],int p,int r)
{
    int j;
    if(p < r)
    {
        j = separa(v,p,r);
        quicksort(v,p,j-1);
        quicksort(v,j+1,r);
    }
}

//funcao principal

int main()
{
    int j,i,n;
    int inicio,final,tmili,soma_mergesort = 0,soma_selecao = 0,soma_bolha = 0,soma_quicksort = 0,soma_insercao = 0,soma_heapsort = 0;
    srand((unsigned)(time(NULL)));
    FILE* fp = fopen("ordenador.txt","wt");
    n = 500;
    do
    {
        int a[n],b[n],c[n],d[n],e[n],f[n],z[n];
        for(i = 0; i < n; i++)
        {
            a[i] = rand();
            b[i] = a[i];
            c[i] = a[i];
            d[i] = a[i];
            e[i] = a[i];
            f[i] = a[i];
            z[i] = a[i];
        }
        int j;
        for(i = 0; i < 200; i++)
        {
            inicio = GetTickCount();
            mergesort(a,0,n);
            final = GetTickCount();
            soma_mergesort += final-inicio;
            for(j = 0; j < n; j++)
                a[j] = rand();
        }
        tmili = final - inicio;
        soma_mergesort += tmili;
        for(i = 0; i < 200; i++)
        {
            inicio = GetTickCount();
            ord_bolha(0,n,b);
            final = GetTickCount();
            int g = final-inicio;
            soma_bolha += g;
            for(j = 0; j < n; j++)
                b[j] = rand();
        }

        for(i = 0; i < 200; i++)
        {
            inicio = GetTickCount();
            selecao(n,c);
            final = GetTickCount();
            int h = final-inicio;
            soma_selecao += h;
            for(j = 0; j < n; j++)
                c[j] = rand();
        }
        for(i = 0; i < 200; i++)
        {
            transforma_vetor(n,e);
            inicio = GetTickCount();
            Heapsort(n,e);
            final = GetTickCount();
            int y = final-inicio;
            soma_heapsort += y;
            for(j = 0; j < n; j++)
                e[j] = rand();
        }

        for(i = 0; i < 200; i++)
        {
            inicio = GetTickCount();
            insercao(f,n);
            final = GetTickCount();
            int po = final-inicio;
            soma_insercao += po;
            for(j = 0; j < n; j++) //acrescenta outros elementos no vetor randocamente
                f[j] = rand();
        }
        for(i = 0; i < 200; i++)
        {
            inicio = GetTickCount();
            quicksort(z,0,n-1);
            final = GetTickCount();
            int de = final-inicio;
            soma_quicksort += de;
            for(j = 0; j < n; j++)
                z[j] = rand();
        }
        //(bolha)  (selecao) (insercao) (heapsort) (mergesort) (quicksort) .
        fprintf(fp,"%d , %f , %f , %f , %f , %f , %f \n"
                ,n,(float)soma_bolha / 200,(float)soma_selecao / 200,(float)soma_insercao / 200,(float)soma_heapsort / 200,(float)soma_mergesort / 200
                ,(float)soma_quicksort / 200);
        n += 500;
    }
    while(n <= 10000);
}
