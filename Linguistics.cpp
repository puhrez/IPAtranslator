//
//  Linguistics.cpp
//  Created by Michael Pérez on 12/09/13.
//
//  This code is meant to be a simple general american english to IPA translator.
//  It is not perfect, so it requires a careful user. But for 80% of the words, an accurate
//  transcription is provided.
//  I wanted to include the more complex alternations, but their implementation, is for now
//  beyond my reach. Perhaps Translate 2.0 for honors project next semester!
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void TranslateIPA(string &sent, ofstream &outfile);

/* function: TranslateIPA
 * input: string, ofstream
 * process: iterates through the string it is passed, checking conditions for switch.
 * output: returns the translated sentence.
 *
 */
void TranslateIPA(string &sent, ofstream &outfile)
{
    string::size_type len = sent.length();
    for(int x= 0; x < len; x++)
    {
        //Vowel alternation conditions
        if(sent[x] == 'a' || sent[x] == 'e' || sent[x] == 'i' || sent[x] == 'u' || sent[x] == 'o')
        {
            if((sent[x] == 'e' || sent[x] == 'i' || sent[x] =='o' || sent[x] =='u' ||sent[x] == 'y')&& sent[x+1] == 'r'
               && (sent[x-1] != 's'|| sent[x-1] != 'p' || sent[x-1] != 'f' || sent[x-1] != 'm' || sent[x-1] !=  'w' || sent[x-1] != 't' || sent[x-1] != 'r'))
            {
                sent.replace(x,2,"ɝ");
            }
            else if(sent[x] == 'a')
            {
                if(sent[x+1] == 's' && sent[x+2] == 'u')
                    sent.replace(x,3,"ʒ");
                else if(sent[x+1] == 't' || sent[x+1] == 'p' || sent[x+1] == 'b' || sent[x+1] == 'g' || sent[x+1] == '?')
                    sent.replace(x,1,"æ");
                else if(sent[x+1] == 'r')
                    sent.replace(x,2,"ɑɹ");
                else if(sent[x+1]== 'y')
                    sent.replace(x,2,"eɪ");
                else if((sent[x-1] == ' ' || x == 0) && sent[x+1] == ' ')
                    sent.replace(x,1,"eɪ");
                else if(sent[x+1] == 'r' && sent[x+2] == 'e')
                    sent.replace(x,3,"ɛɹ");
                else
                    sent.replace(x,1,"ɑ");
            }
            else if(sent[x] == 'o')
            {
                if((sent[x+1] == 'o' || sent[x+1] == 'e')&& (sent[x+2] == ' ' || sent[x+2] == 'd' || sent[x+2] == 'l'))
                    sent.replace(x,2,"u");
                else if((sent[x-1] == 'd' || sent[x-1] == 't') && sent[x+1] == ' ')
                    sent.replace(x,1,"u");
                else if(sent[x+2] == 'u' && sent[x+3] == 'g' && sent[x+4] == 'h')
                {
                    if(sent[x] == 'r' || 't' || 'n')
                        sent.replace(x+1, 4, "ʊf");
                    else
                        sent.replace(x+1,4,"ʊ");
                }
                else if((sent[x+1] == ' ') || (sent[x-1] == 'r' || sent[x-1] == 'l' || 'd'))
                    sent.replace(x,1,"oʊ");
                else if((sent[x+1] == 't' || sent[x+1] =='p' || sent[x+1] =='b' || sent[x+1] =='k' || sent[x+1] =='g' || sent[x+1] =='?' || sent[x+1] =='m' ||sent[x+1] == 'n'))
                    sent.replace(x,1,"ɑ");
                else if(sent[x] == 'o' && sent[x+1] == 'u')
                {
                    if(sent[x-1] == 'y')
                        sent.replace(x,2,"u");
                    else
                        sent.replace(x,2,"ɐ");
                }
                else if(sent[x+1] == 'y')
                    sent.replace(x,2,"ɔɪ");
                else if(sent[x+1] == 'w')
                    sent.replace(x,1,"oʊ");
                else if(sent[x+1] == 'r')
                    sent.replace(x+1,2,"ʊɹ");
            }
            else if(sent[x] == 'e')
            {
                if(sent[x+1] == 'e' || sent[x+1] == 'a')
                   sent.replace(x,2,"i");
                else if((sent[x-1] == 'm') && (sent[x+1] == ' ' || x == len-1))
                {
                    sent.replace(x,1, "i");
                }
                else if(sent[x+1] == ' ' || x == len-1)
                {
                    sent.replace(x,1,"");
                }
                else if((sent[x+1] == 'a' || sent[x+1] == 'e') && sent[x+2] == 'r')
                {
                    sent.replace(x,3,"ɪɹ");
                }
                else if(((x == 0 || sent[x-1] == ' ') || (sent[x-1] == 'h' && sent[x+1] == ' ')) && (sent[x+1] != 'm' && sent[x+1] != 'n'))
                    sent.replace(x,1,"i");
                else
                    sent.replace(x,1,"ɛ");
            }
            else if(sent[x] == 'i')
            {
                if(sent[x+1] == 'g' && sent[x+2] == 'h')
                     sent.replace(x,3,"aɪ");
                else if(sent[x+1] == 'e')
                {
                    sent.replace(x,2,"aɪ");
                }
                else if(sent[x+1] == ' ' && (sent[x-1] == ' ' || x == 0))
                {
                    sent.replace(x+1,1,"aɪ");
                }

                else
                    sent.replace(x,1,"ɪ");

            }
            else if(sent[x] == 'u')
            {
                if(sent[x+1] == 't' || sent[x+1] == 'p' || sent[x+1] == 'b' || sent[x+1] == 'k' || sent[x+1] == 'g' || sent[x+1] == '?')
                    sent.replace(x,1,"ʌ");
            }
        }
        
        //Consonant alternation conditions
        else
        {
            if(sent[x] == 'c')
            {
                if(sent[x+1] == 'k')
                    sent.replace(x,2,"k");
                else if(sent[x+1] == 't')
                    sent.replace(x,1,"k");
                else if(sent[x+1] == 'h')
                    sent.replace(x,2,"tʃ");
                else if(x == 0 && sent[x+1] == 'h')
                    sent.replace(x,2,"tʃ");
                else if(sent[x+1] == ' ' || x == len-1)
                    sent.replace(x,1,"s");
                else if(sent[x+2] == ' ')
                    sent.replace(x,2,"s");
                
            }
            else if(sent[x] == 'd')
            {
                if(sent[x+1] == 'j')
                    sent.replace(x,2, "dʒ");
            }
            else if(sent[x] == 's')
            {
                if(sent[x+1] == 'h')
                    sent.replace(x,2, "ʃ");
                else if(sent[x+1] == 's')
                    sent.replace(x,2,"s");
            }
            else if(sent[x] == 't')
            {
                if(x == 0 && sent[x+1] == 'h')
                    sent.replace(x,2, "θ");
                else if(sent[x+1] == 'h')
                    sent.replace(x,2, "ð");
                else if(sent[x+1] == 't')
                    sent.replace(x, 2, "?");
            }
            else if(sent[x] == 'x')
            {
                sent.replace(x,1, "ks");
            }
            else if(sent[x] == 'h' && sent[x+1] == 'o' && (sent[x+2] == ' ' || x+2 == len))
            {
                if(sent[x-1] == 'w')
                    sent.replace(x-1,3,"hu");
                else
                    sent.replace(x+1,2,"u");
            }
            else if(sent[x] == 'l' && sent [x+1] == 'd')
            {
                if(sent[x+1] == 'd')
                    sent.replace(x,2,"d");
                else if(sent[x+1] == 'l')
                    sent.replace(x,2,"l");
            }
            else if(sent[x] == 'r' && sent[x+1] == 'r')
            {
                sent.replace(x,2, "r");
            }
            else if(sent[x] == 'y')
            {
                if(sent[x-1] != ' ')
                    sent.replace(x,1,"aɪ");
                else if(sent[x-1] != 'l')
                    sent.replace(x,1,"i");
                else
                    sent[x] = 'j';
            }
            else if(sent[x] == 'n')
            {
                if(sent[x+1] == 'g')
                    sent.replace(x,2,"ŋ");
            }
        }
        //refreshing the length of the string
        len = sent.length();
    }
}

int main()
{
    string sent;
    
    //establishing fstream links
	ifstream infile("/Users/admin/Dropbox/MacaulayHonorsCollegeatBrooklynCollege/Linguistics/input.txt");
	//ifstream infile("/dev/stdin"); //uncomment for debug
	ofstream outfile("/Users/admin/Dropbox/MacaulayHonorsCollegeatBrooklynCollege/Linguistics/output.txt");
	//ofstream outfile("/dev/stdout/");
	
    outfile << "Welcome to IPA translator" << endl<<endl;;
    //while(sent!="-1"){ //uncomment for loop
    cout << "Please enter your sentence:"<<endl;
    getline(infile,sent, '.');
    outfile << "\nThe original sentence is:" << endl << sent << endl << endl;;
    TranslateIPA(sent, outfile);
    outfile << "The translated sentence is:" << endl << "/"<< sent << "/" << endl <<endl;
    //}
    
    //closing the files
    infile.close();
    outfile.close();
	
	return 0;
}