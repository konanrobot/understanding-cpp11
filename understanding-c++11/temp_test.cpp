#include "inc.h"
#include "gtest/gtest.h"
#include <vector>
USING_NS_STD;

TEST(TempTest, Dummy) {
	vector<int> vi;
	vector<int> vb{ 1, 2, 3 };
	vb.assign(vi.begin(), vi.end());
	psln(vb.size());
}