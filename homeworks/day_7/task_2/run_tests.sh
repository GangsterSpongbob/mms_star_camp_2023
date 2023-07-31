#! bin/bash

if [ $(./out.exe "$(cat tests/1.in)") -eq "$(cat tests/1.out)" ]; then
		echo "Test 1 passed succesfully."
else
		echo "Test 1 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/2.in)") -eq "$(cat tests/2.out)" ]; then
		echo "Test 2 passed succesfully."
else
		echo "Test 2 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/3.in)") -eq "$(cat tests/3.out)" ]; then
		echo "Test 3 passed succesfully."
else
		echo "Test 3 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/4.in)") -eq "$(cat tests/4.out)" ]; then
		echo "Test 4 passed succesfully."
else
		echo "Test 4 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/5.in)") -eq "$(cat tests/5.out)" ]; then
		echo "Test 5 passed succesfully."
else
		echo "Test 5 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/6.in)") -eq "$(cat tests/6.out)" ]; then
		echo "Test 6 passed succesfully."
else
		echo "Test 6 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/7.in)") -eq "$(cat tests/7.out)" ]; then
		echo "Test 7 passed succesfully."
else
		echo "Test 7 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/8.in)") -eq "$(cat tests/8.out)" ]; then
		echo "Test 8 passed succesfully."
else
		echo "Test 8 unsuccessfull."
fi

if [ $(./out.exe "$(cat tests/9.in)") -eq "$(cat tests/9.out)" ]; then
		echo "Test 9 passed succesfully."
else
		echo "Test 9 unsuccessfull."
fi
