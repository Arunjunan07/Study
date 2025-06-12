function countDigits(n:number):number{
    let count:number = 0;
    while(n>0)
    {
        count +=1;
        n = Math.floor(n/10);
    }
    return count;
}

console.log(countDigits(124));


function fibanacci(n){
    let a = 0;
    let b = 1;
   
    for(let i = 0;i<n;i++)
    {
        console.log(a,"\t");
        let c = a+b;
        a=b;
        b=c;
    }
}

fibanacci(7);


function Palindrome(n: number): boolean;   
function Palindrome(str: string): boolean;  

function Palindrome(input: number | string): boolean {
    if (typeof input === 'number') {
        let n = input;
        let temp = n;
        let num = 0;
        while (n > 0) {
            let r = n % 10;
            num = num * 10 + r;
            n = Math.floor(n / 10);
        }
        return num === temp;
    } else {
        let rev = input.split('').reverse().join('');
        return input === rev;
    }
}

console.log(Palindrome(121))
console.log(Palindrome("hello")); 
console.log(Palindrome("madam")); 
