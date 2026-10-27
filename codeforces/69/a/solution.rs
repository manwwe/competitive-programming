use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut iter = input.split_whitespace();

    let t: usize = iter.next().unwrap().parse().unwrap();

    let (mut sx, mut sy, mut sz) = (0, 0, 0);

    for _ in 0..t {
        let x: i32 = iter.next().unwrap().parse().unwrap();
        let y: i32 = iter.next().unwrap().parse().unwrap();
        let z: i32 = iter.next().unwrap().parse().unwrap();

        sx += x;
        sy += y;
        sz += z;
    }

    let result = if sx == 0 && sy == 0 && sz == 0 {
        "YES"
    } else {
        "NO"
    };

    println!("{}", result);
}
