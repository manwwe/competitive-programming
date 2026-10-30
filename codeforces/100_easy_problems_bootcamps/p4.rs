#![allow(unused)]

use std::io::stdin;

fn take_int() -> usize {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    return input.trim().parse().unwrap()
}

fn take_string() -> String {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    input.trim().to_string()
}

fn take_vector() -> Vec<usize> {
    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
    let arr: Vec<usize> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
    return arr;
}


pub fn main() {
    let n = take_string().to_lowercase();
    let m = take_string().to_lowercase();

    let n = n.as_bytes();
    let m = m.as_bytes();

    for i in 0..n.len() {
        if n[i] < m[i] {
            println!("-1");
            return;
        }
        if n[i] > m[i] {
            println!("1");
            return;
        }
    }

    println!("0");

}
