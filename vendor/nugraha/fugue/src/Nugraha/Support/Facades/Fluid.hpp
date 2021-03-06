namespace Nugraha { namespace Support { namespace Facades {

class Fluid 
{
public:
    static int baseArg;

    /**
     * Menggabungkan semua string yang dimasukkan sebagai parameter.
     * 
     * @param int n_args [Jumlah seluruh argumen]
     */
    static char* concat(int n_args, ...)
    {
        short int baseArgumentCount = Fluid::baseArg;
        char* holder = NULL;

        va_list argumentList;
        va_start(argumentList, n_args);

        int totalCharacters = 0;
        short int count = 0;

        for(int i = baseArgumentCount + 1; i <= n_args; i++) {

            char* text = va_arg(argumentList, char*);
            totalCharacters += strlen(text);

            char* tempText = new char[strlen(holder)+1];
            strcpy(tempText, holder);

            delete holder;
            holder = NULL;

            holder = new char[totalCharacters + 1];

            strcpy(holder, tempText);
            strcat(holder, text);

            delete tempText;
        }
        va_end(argumentList);

        return holder;
    }

    /**
     * Fungsi pembantu untuk merubah String menjadi char array.
     * 
     * @param stringText    [Object String yang akan diubah]
     * @param charArrayText [pointer yang akan menjadi tempat hasil disimpan]
     */
    static void string2CharArray(String stringText, char** charArrayText)
    {
        *charArrayText = NULL;
        *charArrayText = new char[stringText.length()+1];
        stringText.toCharArray(*charArrayText, stringText.length()+1);
    }
};
}}}

int Nugraha::Support::Facades::Fluid::baseArg = 1;