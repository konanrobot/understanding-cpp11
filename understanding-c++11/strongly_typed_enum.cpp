#include "strongly_typed_enum.h"

NS_BEGIN(elloop)
NS_BEGIN(strongly_typed_enum)

TEST(StrongEnum, UseTest) {
	//kSampleEnum e1(Dog);				// error: strong scope type. must use::
	kAnimal dog(kAnimal::Dog);
	EXPECT_EQ(-111, (int)dog);
	EXPECT_EQ(-110, static_cast<int>(kAnimal::Cat));
	EXPECT_EQ(-110, (int)kAnimal::Cat);
	EXPECT_GT(kAnimal::Cat, dog);

	kAnimal cat(kAnimal::Cat);
	EXPECT_LT(dog, cat);

	kCar jeep(kCar::Jeep);
	kCar tank(kCar::Tank);
	EXPECT_EQ(0, (int)jeep);
	EXPECT_EQ(1, (int)tank);

	//EXPECT_GT(jeep, dog);			// error:different enum type.
}

NS_END(strongly_typed_enum)
NS_END(elloop)