use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen: HashMap<i32, usize> = HashMap::new();

        for (i, v) in nums.iter().enumerate() {
            let complement = target - *v;

            if let Some(&index) = seen.get(&complement) {
                return vec![index as i32, i as i32];
            }

            seen.insert(*v, i);
        }

        vec![]
    }
}
