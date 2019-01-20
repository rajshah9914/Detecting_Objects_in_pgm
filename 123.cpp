#include<iostream>
#include<bits/stdc++.h>
#include <fstream> // ifstream
#include <sstream> // stringstream

using namespace std;
int main()
{
  int row = 0, col = 0, numrows = 0, numcols = 0,numcols1,numrows1;
//   ifstream infile("peep.pgm");
  string file_name;
  cout<<"Enter the file name";
//   cin>>file_name;
  getline( cin, file_name );
  ifstream infile(file_name.c_str());
  stringstream ss;
  string inputLine = "";
  
  // First line : version
  getline(infile,inputLine);
  if(inputLine.compare("P2") != 0) cerr << "Version error" << endl;
  else cout << "Version : " << inputLine << endl;

  // Second line : comment
  getline(infile,inputLine);
  cout << "Comment : " << inputLine << endl;

  // Continue with a stringstream
  ss << infile.rdbuf();
  // Third line : size
   ss >> numcols1;
   int count=0,count1=0;
   for(int i=0;inputLine[i]!=' ';i++)
   count=count+1;
   for(int j=count+1;inputLine[j]!='\0';j++)
   count1=count1+1;
for(int i=0;inputLine[i]!=' ';i++)
{
numcols+=(inputLine[i]-48)*pow(10,(count-i-1));
//numcols+=(inputLine[i+count1]-48)*pow(10,(count1-i-1));
}
for(int j=count+1;inputLine[j]!='\0';j++)
{
numrows+=(inputLine[j]-48)*pow(10,(count1-1));
count1--;
}
  cout << numcols << " columns and " << numrows << " rows" << endl;

  int array[numrows][numcols],a[numrows][numcols];
  for(row = 0; row < numrows; ++row)
    for (col = 0; col < numcols; ++col) a[row][col]=0;

  // Following lines : data
  for(row = 0; row < numrows; ++row)
  {
    for (col = 0; col < numcols; ++col) 
    {
        ss >> array[row][col];
        //  cout << array[row][col] << " ";
    }
    // cout << endl;
  }

  // Now print the array to see the result
  for(row = 0; row < numrows; ++row) {
    for(col = 0; col < numcols; ++col) {
        if(array[row][col]>0 && array[row][col]<=128)
        array[row][col]=1;
        else if(array[row][col]<0)
        array[row][col]=0;
        cout << array[row][col] << " ";
    }
    cout << endl;
  }
  infile.close();
  ofstream myfile;
  myfile.open ("/home/rajshah9914/Desktop/Untitled Folder/csv-to-html-table-master/data/example.csv");
  int i,j,k,k1,min,min1;
  cout<<"Enter number of shapes of object needed to be detected";
  int no_shapes;
  cin>>no_shapes;
  printf("Enter number of squares to be detected");
  int no_sq,no_rect;
  cin>>no_sq;
  printf("Enter number of rectangles to be detected");
  cin>>no_rect;
  if(no_rect+no_sq==no_shapes)
  {
      myfile<<"X"<<","<<"Y"<<","<<"Shape\n";
  for(i=0;i<numrows;i++)
  {
      for(j=0;j<numcols;j++)
      {
        //   cout << i << " " << j  << " " << a[i][j] << "\n";
          if(array[i][j]&&a[i][j]==0)
          {
            //   cout << i << " " << j << "\n";
              for(k1=i;k1<numrows;k1++)
              {
                  int c=1;
                  if(array[k1][j]==0)
                  {
                      break;
                  }
                  else{
                      a[k1][j]=1;
                  }
              for(k=j+1;k<numcols;k++)
              {
                  if(array[k1][k])
                  {
                      c++;
                      a[k1][k]=1;
                  }
                  else
                  {
                      if(k1==i)
                      {
                          min=c;
                      }
                      else if(c<=min)
                      {
                          min=c;
                          //min++;
                      }
                      break;
                  }
              }
              }
              min1=k1-i;
            //   cout << min  << " " << min1 << "\n";
              if(min==min1)
              {
                  if(no_sq>0)
                  {
                  cout << i << " " << j << " " << "square" << "\n";
                  myfile<<i<<","<<j<<","<<"Square\n";
                  no_sq--;
                  }
              }
              else if(min!=1)
              {
                  if(no_rect>0)
                  {
                  cout << i << " " << j << " " << "rectangle" << "\n";
                  myfile<<i<<","<<j<<","<<"Rectangle\n";
                  no_rect--;
                  }
              }
          }
      }
  }
  }
  else{
      cout<<"Please enter correct info"<<endl;
  }
    myfile.close();
  return 0;
}