 int count = 0;

    // Iterate through each element of arr1
    for (int i = 0; i < arr1.size(); ++i) {
        bool isValid = true;  // Assume arr1[i] will be valid unless proven otherwise
        
        // Iterate through each element of arr2
        for (int j = 0; j < arr2.size(); ++j) {
            // If the absolute difference is less than or equal to d, it's not a valid element for counting
            if (abs(arr1[i] - arr2[j]) <= d) {
                isValid = false;
                break;  // No need to check further elements in arr2 for this arr1[i]
            }
        }

        // If arr1[i] is valid (no element in arr2 satisfies the condition), increment count
        if (isValid) {
            count++;
        }
    }

    return count;
