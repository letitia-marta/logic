#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int main()
{
    // COMENTARIU CEVA
    
    /**Voi folosi urmatoarele simboluri:
       & pentru ∧
       / pentru ∨
       | pentru ¬
       - pentru ⇒
       _ pentru ⇔

       Presupun ca nu se citesc decat simboluri adecvate unei formule propozitionale.
    */

    char v[256],c,con[]="&/|-_";
    int n=0;
    while (fin>>c)
        v[n++]=c;
    if (n==1 && v[0]>='A' && v[0]<='Z')
        fout<<"Este propozitie atomica.";
    else if (n==1 && (v[0]=='(' || v[0]==')' || strchr(con,v[0])))
        fout<<"Nu este formula.";
    else if (n>1 && (v[0]!='(' || v[n-1]!=')'))
        fout<<"Nu este formula.";
    else if (n>1 && v[0]=='(' && v[n-1]==')')
    {
        bool ok=true;
        int conectori=0;
        int ps=1,pd=1; //contorizez parantezele stangi si drepte
        for (int i=1; i<n-1; i++)
        {
            if (v[i]=='(')
                ps++;
            else if (v[i]==')')
                pd++;
            if (strchr(con,v[i]))
                conectori++;
            if (!(ps==pd && ps ==conectori))
                ok=false;
            else
            {
                if (v[i]>='A' && v[i]<='Z' && v[i+1]>='A' && v[i+1]<='Z')
                {
                    //propozitii atomice consecutive
                    ok=false;
                    break;
                }
                else if (strchr(con,v[i]) && strchr(con,v[i+1]))
                {
                    //conectori consecutivi
                    ok=false;
                    break;
                }
                else if (v[i]>='A' && v[i]<='Z' && (v[i+1]=='(' || v[i+1]=='|'))
                {
                    //paranteza deschisa dupa propozitie sau negatie dupa propozitie
                    ok=false;
                    break;
                }
                else if (strchr(con,v[i]) && v[i+1]==')')
                {
                    //paranteza inchisa dupa conector
                    ok=false;
                    break;
                }
                else if (v[i]=='(' && v[i+1]==')')
                {
                    //paranteza inchisa dupa paranteza deschisa
                    ok=false;
                    break;
                }
                else if (v[i]==')' && v[i+1]=='|')
                {
                    //negatie dupa paranteza inchisa
                    ok=false;
                    break;
                }
                else if (v[i-1]=='(' && v[i]>='A' && v[i]<='Z' && v[i+1]==')')
                {
                    //propozitie atomica intre paranteze
                    ok=false;
                    break;
                }
            }
        }
        if (ps!=pd)
            ok=false;
        if (ok==true)
            fout<<"Este formula propozitionala.";
        else
            fout<<"Nu este formula propozitionala.";
    }
    return 0;
}
