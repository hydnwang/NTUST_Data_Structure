#ifndef POLY_H
#define POLY_H

#include <string>

using namespace std;

class Poly; // forward declaration

enum Triple
{
    var,
    ptr,
    no
};

class PolyNode
{
    friend class Poly;
    PolyNode(){}; //default constuctor

    // Constucting 3 types of polynomial node.
    // trio: var, variable, exponent(0) and next
    PolyNode(Triple triop, char vblep, int expp = 0) : trio(triop), vble(vblep), exp(expp), next(0){};
    // trio: ptr, down, exponent and next
    PolyNode(Triple triop, int expp) : trio(triop), exp(expp), down(0), next(0){};
    // triop: no, coefficient, exponent and next
    PolyNode(Triple triop, int coefp, int expp) : trio(triop), coef(coefp), exp(expp), next(0){};

  private:
    Triple trio;
    union {
        PolyNode *down;
        int coef;
        char vble;
    };
    int exp;
    PolyNode *next;
};

class Poly
{
  public:
    // default constuctor
    Poly() { first = nullptr; };

    PolyNode *scanNode(PolyNode *node, int exp);
    string printPoly(PolyNode *node);
    void insertNode(int coef, int ex, int ey, int ez);
    int retCoeff(int ex, int ey, int ez);
    void Mulf(int ex, int ey, int ez);

  private:
    PolyNode *first;
};

PolyNode *Poly::scanNode(PolyNode *node, int exp)
{
    PolyNode *currentNode = node;
    PolyNode *previousNode;
    while (currentNode)
    {
        if (currentNode->exp == exp)
            return currentNode;
        else
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }
    return previousNode;
}

string Poly::printPoly(PolyNode *node = NULL)
{
    string p, v;
    PolyNode *currentNode = node;

    if (!node)
    {
        v.push_back(first->vble);
        currentNode = first->next;
    }
    else
    {
        v.push_back(node->vble);
        currentNode = node->next;
    }

    while (currentNode)
    {
        if (currentNode->trio == ptr)
        {
            p += "( ";
            p += printPoly(currentNode->down);
            p += v + "^";
            p += to_string(currentNode->exp);
            p += " )";
        }
        else if (currentNode->trio == no)
        {
            p += to_string(currentNode->coef);
            p += v + "^";
            p += to_string(currentNode->exp);

        }
        currentNode = currentNode->next;

        if (currentNode)
        {
            p += " + ";
        }
    }
    return p;
}

void Poly::insertNode(int coef, int ex, int ey, int ez)
{
    // cout << "coef: " << coef << ", ex: " << ex << ", ey: " << ey << ", ez: " << ez << endl;
    if (!first)
    {
        PolyNode *headNodeZ = new PolyNode(var, 'z');
        first = headNodeZ;
        PolyNode *nodeZ = new PolyNode(ptr, ez);
        first->next = nodeZ;

        PolyNode *headNodeY = new PolyNode(var, 'y');
        nodeZ->down = headNodeY;
        PolyNode *nodeY = new PolyNode(ptr, ey);
        headNodeY->next = nodeY;

        PolyNode *headNodeX = new PolyNode(var, 'x');
        nodeY->down = headNodeX;
        PolyNode *nodeX = new PolyNode(no, coef, ex);
        headNodeX->next = nodeX;
    }
    else
    {
        PolyNode *currentNode = scanNode(first->next, ez);
        // find ez
        if (currentNode->exp == ez)
        {
            currentNode = scanNode(currentNode->down->next, ey);
            // find ey
            if (currentNode->exp == ey)
            {
                currentNode = scanNode(currentNode->down->next, ex);
                // find ex
                if (currentNode->exp == ex)
                {
                    currentNode->coef += coef;
                }
                else
                {
                    PolyNode *nodeX = new PolyNode(no, coef, ex);
                    currentNode->next = nodeX;
                }
            }
            else
            {
                PolyNode *nodeY = new PolyNode(ptr, ey);
                currentNode->next = nodeY;

                PolyNode *headNodeX = new PolyNode(var, 'x');
                nodeY->down = headNodeX;
                PolyNode *nodeX = new PolyNode(no, coef, ex);
                headNodeX->next = nodeX;
            }
        }
        else
        {
            PolyNode *nodeZ = new PolyNode(ptr, ez);
            currentNode->next = nodeZ;

            PolyNode *headNodeY = new PolyNode(var, 'y');
            nodeZ->down = headNodeY;
            PolyNode *nodeY = new PolyNode(ptr, ey);
            headNodeY->next = nodeY;

            PolyNode *headNodeX = new PolyNode(var, 'x');
            nodeY->down = headNodeX;
            PolyNode *nodeX = new PolyNode(no, coef, ex);
            headNodeX->next = nodeX;
        }
    }
    return;
};

int Poly::retCoeff(int ex, int ey, int ez)
{
    int result = -1;
    PolyNode *currentNode = scanNode(first->next, ez);
    // find ez
    if (currentNode->exp == ez)
    {
        currentNode = scanNode(currentNode->down->next, ey);
        // find ey
        if (currentNode->exp == ey)
        {
            currentNode = scanNode(currentNode->down->next, ex);
            // find ex
            if (currentNode->exp == ex)
            {
                result = currentNode->coef;
            }
        }
    }
    return result;
};

void Poly::Mulf(int ex, int ey, int ez)
{
    PolyNode *currentNodeZ = first->next;

    while (currentNodeZ)
    {
        currentNodeZ->exp += ez;
        if (currentNodeZ->trio == ptr)
        {
            PolyNode *currentNodeY = currentNodeZ->down->next;
            while (currentNodeY)
            {
                currentNodeY->exp += ey;
                if (currentNodeY->trio == ptr)
                {
                    PolyNode *currentNodeX = currentNodeY->down->next;
                    while (currentNodeX)
                    {
                        currentNodeX->exp += ex;
                        currentNodeX = currentNodeX->next;
                    }
                }
                currentNodeY = currentNodeY->next;
            }
        }
        currentNodeZ = currentNodeZ->next;
    }
};

#endif
