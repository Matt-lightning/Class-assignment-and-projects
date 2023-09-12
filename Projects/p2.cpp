#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

string readFile(string filename)
{
  ifstream f;

  f.open(filename);

  if(f.is_open())
  {
    string text = "";
    string tmp;

    while( getline(f, tmp) ) text.append(tmp + " ");

    f.close();

    return text;
  }
  else return "";
}

void scanNum(string file, int* values, int* valCount)
{
  int curr = 0;
  bool neg = false;

  for(unsigned int i = 0; i < file.size(); i++)
  {
    //cout << file.at(i) << "\t" << curr << endl;
    if(isdigit(file.at(i)))
    {
      if(file.at(i) == '0' && curr == 0)
      {
        values[*valCount] = 0;
        *valCount += 1;
        neg = false;
        continue;
      }
      curr *= 10;
      curr += (file.at(i) - '0');
    }
    else if(file.at(i) == '-')
    {
      neg = true;
    }
    else
    {
      if(curr != 0)
      {
        if(neg) curr *= -1;
        values[*valCount] = curr;
        *valCount += 1;
        curr = 0;
        neg = false;
      }
    }
  }
  return;
}

void scanString(string file, string *words, int *count)
{
  int last = 0;

  for(unsigned int i = 0; i < file.size(); i++)
  {
    
    if(!isalpha(file.at(i)))
    {
      
      words[*count] = file.substr(last, i - last);
      *count += 1;

      while(!isalpha(file.at(i)) && i < file.size() - 1) i++;
      last = (int)i;
    }
  }
  return;
}

void findDupesNum(int *a0, int *c0, int *a1, int *c1, int *d, int *c)
{
  for(int i = 0; i < *c0; i++)
  {
    int curr = a0[i];

    for(int j = 0; j < *c1; j++)
    {
      if(a1[j] == curr)
      {
        bool unique = true;

        for(int k = 0; k < *c; k++)
        {
          if(d[k] == curr) unique = false;
        }
        if(unique)
        {
          d[*c] = curr;
          *c += 1;
        }
      }
    }
  }
  return;
}

void findDupesString(string *w0, int *c0, string *w1, int *c1, string *w, int *c)
{
  for(int i = 0; i < *c0; i++)
  {
    string curr = w0[i];

    for(int j = 0; j < *c1; j++)
    {
      if(curr.compare(w1[j]) == 0)
      {
        bool unique = true;
        

        for(int k = 0; k < *c; k++)
        {
          if(curr.compare(w[k]) == 0) unique = false;
        }

        if(unique)
        {
          w[*c] = curr;
          *c += 1;
        }
      }
    }
  }
  return;
}

void mergeNum(int *array, int l, int m, int r)
{
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++) larr[i] = array[l+i];
   for(j = 0; j<nr; j++) rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;

   while(i < nl && j < nr)
   {
      if(larr[i] <= rarr[j])
      {
         array[k] = larr[i];
         i++;
      }
      else
      {
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i < nl)
   {
      array[k] = larr[i];
      i++; k++;
   }
   while(j < nr)
   {
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSortNum(int *array, int l, int r)
{
   if(l < r)
   {
      int m = l+(r-l)/2;
      
      mergeSortNum(array, l, m);
      mergeSortNum(array, m+1, r);
      mergeNum(array, l, m, r);
   }
}

void mergeString(string *array, int l, int m, int r)
{
   int i, j, k, nl, nr;

   nl = m-l+1; nr = r-m;

   string larr[nl], rarr[nr];

   for(i = 0; i<nl; i++) larr[i] = array[l+i];
   for(j = 0; j<nr; j++) rarr[j] = array[m+1+j];

   i = 0; j = 0; k = l;

   while(i < nl && j < nr)
   {
      if(larr[i] <= rarr[j])
      {
         array[k] = larr[i];
         i++;
      }
      else
      {
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i < nl)
   {
      array[k] = larr[i];
      i++; k++;
   }
   while(j < nr)
   {
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSortString(string *array, int l, int r)
{
   if(l < r)
   {
      int m = l+(r-l)/2;

      mergeSortString(array, l, m);
      mergeSortString(array, m+1, r);
      mergeString(array, l, m, r);
   }
}

int main(int argc, char** argv)
{
  if(argc != 4)
  {
    cout << "[ERROR]: Correct usage is " << argv[0] << " [TYPE] [FILE 1] [FILE 2]" << endl;
    return 0;
  }
  else
  {
    string file1 = readFile(argv[2]);
    string file2 = readFile(argv[3]);

    if(file1.compare("") == 0 || file2.compare("") == 0)
    {
      cout << "[ERROR]: One or more files could not be opened for reading" << endl;
      return 0;
    }

    if(argv[1][0] == 's' || argv[1][0] == 'S')
    {
      string w0[5000], w1[5000];
      int c0 = 0, c1 = 0;

      scanString(file1, w0, &c0);
      scanString(file2, w1, &c1);

      string w[5000];
      int c = 0;

      findDupesString(w0, &c0, w1, &c1, w, &c);

      mergeSortString(w, 0, c - 1);

      for(int i = 0; i < c; i++) cout << w[i] << endl;

      return 0;
    }

    else if(argv[1][0] == 'i' || argv[1][0] == 'I')
    {
      ;
      int a0[5000], c0 = 0,
          a1[5000], c1 = 0;

      scanNum(file1, a0, &c0);
      scanNum(file2, a1, &c1);

      int a[5000], c = 0;

      findDupesNum(a0, &c0, a1, &c1, a, &c);

      mergeSortNum(a, 0, c - 1);

      for(int i = 0; i < c; i++) cout << a[i] << endl;

      return 0;
    }

    else
    {
      cout << "ERROR: Correct types are i (integer) or s (string)" << endl;
      return 0;
    }
  }
  
  return 0;
}