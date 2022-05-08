#pragma once
#include <sstream>
#include "body.h"

class Body2D : BodyInterface
{
public:
    virtual bool IsThisAreaGreaterThen(const std::vector<Body2D*>& ListOfObject) const
    {
        double SumArea{0};
        for(unsigned int i = 0; i < ListOfObject.size(); i++)
        {
            SumArea += ListOfObject[i]->CalculateArea();
        }

        if(CalculateArea() > SumArea)
        {
            return true;
        } else
        {
            return false;
        }

    }

    virtual std::vector<Point> getVerteces() const override
    {
        return mVerteces;
    }

    virtual std::string Serialization() const override
    {
        std::string DataString;
        DataString.append(std::to_string(mVerteces.size()) + "\t");
        for(unsigned int i = 0; i < mVerteces.size(); i++)
        {
            DataString.append(std::to_string(i) + "\t" +
                              std::to_string(mVerteces[i].x) + "\t " +
                              std::to_string(mVerteces[i].y) + "\t ");
        }
        return DataString;
    }

protected:
    std::vector<Point> mVerteces;
};

class Triangle: public Body2D
{
public:

    Triangle(const std::string& StringOfVertex)
    {

        std::stringstream StreamTemp(StringOfVertex);
        unsigned int numberOfVertex{0};
        StreamTemp >> numberOfVertex;

        mVerteces.resize(3);
        if (numberOfVertex == 3)
        {

            unsigned int CountVertex{0};
            while(CountVertex < 3)
            {

                StreamTemp >> mVerteces[CountVertex].x;
                StreamTemp >> mVerteces[CountVertex].y;
                CountVertex++;
            }
            mSideA = CalcDistanse(mVerteces[0], mVerteces[1]);
            mSideB = CalcDistanse(mVerteces[0], mVerteces[2]);
            mSideC = CalcDistanse(mVerteces[1], mVerteces[2]);
            mHalfPerimeter = (mSideA + mSideB + mSideC) / 2;
        }
    }

    Triangle(const Point& Left, const Point& Right, const Point& Top)
    {
        mSideA = CalcDistanse(mVerteces[0], mVerteces[1]);
        mSideB = CalcDistanse(mVerteces[0], mVerteces[2]);
        mSideC = CalcDistanse(mVerteces[1], mVerteces[2]);
        mHalfPerimeter = (mSideA + mSideB + mSideC) / 2;
        mVerteces[0] = Left;
        mVerteces[1] = Right;
        mVerteces[2] = Top;
    }

    virtual double CalculateArea() const override
    {

        return std::sqrt(mHalfPerimeter * (mHalfPerimeter - mSideA) * (mHalfPerimeter - mSideB) * (mHalfPerimeter - mSideC));
    }

private:
    double mSideA {0};
    double mSideB {0};
    double mSideC {0};
    double mHalfPerimeter {0};
};

class Square : public Body2D
{
public:
    Square(const Point& LeftBottom, const Point& RightTop)
    {
        mVerteces.resize(4);
        mVerteces[0] = LeftBottom;
        mVerteces[2] = RightTop;
        mVerteces[1].x = LeftBottom.x;
        mVerteces[1].y = RightTop.y;
        mVerteces[3].x = RightTop.x;
        mVerteces[3].y = LeftBottom.y;
        mSide = CalcDistanse(mVerteces[0], mVerteces[1]);
    }

    Square(const std::string& StringOfVertex)
    {

        std::stringstream StreamTemp(StringOfVertex);

        unsigned int numberOfVertex{0};

        StreamTemp >> numberOfVertex;
        if (numberOfVertex == 4)
        {
            unsigned int CountVertex{0};
            mVerteces.resize(4);
            while(CountVertex < 4)
            {

                StreamTemp >> mVerteces[CountVertex].x;
                StreamTemp >> mVerteces[CountVertex].y;
                CountVertex++;
            }
            mSide = CalcDistanse(mVerteces[0], mVerteces[1]);
        }
    }

    virtual double CalculateArea() const override
    {
        return mSide*mSide;
    }

private:
    double mSide{0};
};

class Circle : public Body2D
{
public:
    Circle(const Point& Center, const double Radius)
        : mRadius(Radius)
    {
        mVerteces.resize(1);
        mVerteces[0] = Center;
    }

    Circle(const std::string& CircleInString)
    {
        std::stringstream StreamTemp(CircleInString);
        unsigned int numberOfVertex{0};
        StreamTemp >> numberOfVertex;
        if (numberOfVertex == 1)
        {
            mVerteces.resize(1);
            StreamTemp >> mVerteces[0].x;
            StreamTemp >> mVerteces[0].y;
            StreamTemp >> mRadius;
        }
    }

    virtual double CalculateArea() const override
    {
        return M_PI * mRadius * mRadius;
    }

    double getRadius() const
    {
        return mRadius;
    }

    virtual std::string Serialization() const override
    {
        std::string DataString;
        DataString.append(std::to_string(mVerteces.size()) + "\t" +
                          std::to_string(mVerteces[0].x) + "\t " +
                          std::to_string(mVerteces[0].y) + "\t " +
                          std::to_string(mRadius));
        return DataString;
    }
private:
    double mRadius {0};
};
