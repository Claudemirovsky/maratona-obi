/* Leetcode - Pascal's Triangle 01 */
// Necessário apenas pra compilar localmente.
struct Solution;

/// Código á ser enviado ao leetcode.
impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut rows: Vec<Vec<i32>> = vec![];
        for line in 1..=num_rows {
            let mut items: Vec<i32> = vec![];
            let mut num = 1;
            for i in 1..=line {
                items.push(num);
                num *= line - i;
                num /= i;
            }
            rows.push(items);
        }

        return rows;
    }
}

/// Teste local
fn main() {
    let cols = Solution::generate(5);
    println!("{:?}", cols);
}
