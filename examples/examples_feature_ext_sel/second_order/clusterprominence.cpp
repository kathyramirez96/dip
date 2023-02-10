#include "dicom_read/DicomReader.h"
#include "second_order/clusterprominence.h"
#include <fstream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

vector<vector<int>> parseData(int **img, int size, int feat)
{
    std::vector<std::vector<int>> data;

    for (int i = 0; i < size; ++i)
    {
        std::vector<int> featureSet;
        for (int j = 0; j < feat; ++j)
        {
            featureSet.push_back(img[i][j]);
        }

        data.push_back(featureSet);
    }
    return data;
}

int main(int argc, char *argv[])
{
    DicomReader dicomObj("/home/edwin/Documents/Proyecto Final Edwin Iza/dip/data/20586908_6c613a14b80a8591_MG_R_CC_ANON.dcm");
    int size = dicomObj.getHeight();
    int elements = dicomObj.getWidth();

    vector<vector<int>> image = parseData(dicomObj.getImageArray(12), size, elements);

    ClusterP cp;

    double calcularteCP  = cp.CP(image);
    cout << "Cluster Prominence: " << calcularteCP << endl;
    double calcularteCP = cp.CP_OPM(image);
    cout << "Cluster Prominence using OMP: " << calcularteCP << endl;

    return 0;
}

