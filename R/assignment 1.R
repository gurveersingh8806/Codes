
# 1.Check if a Number is Prime

isPrime <- function(num) {
  if (num <= 1) {
    return(FALSE)
  }
  for (i in 2:(num - 1)) {
    if (num %% i == 0) {
      return(FALSE)
    }
  }
  return(TRUE)
}

# Example
n <- as.integer(readline("Enter a number: "))
if (isPrime(n)) {
  cat(n, "is a Prime Number\n")
} else {
  cat(n, "is NOT a Prime Number\n")
}


# 2. Find Factorial of a Number

findFactorial <- function(num) {
  if (num < 0) {
    return("Factorial not defined for negative numbers")
  }
  fact <- 1
  for (i in 1:num) {
    fact <- fact * i
  }
  return(fact)
}

# Example
n <- as.integer(readline("Enter a number: "))
cat("Factorial of", n, "is", findFactorial(n), "\n")


# 3. Check Whether a Number is Even or Odd

checkEvenOdd <- function(num) {
  if (num %% 2 == 0) {
    return("Even Number")
  } else {
    return("Odd Number")
  }
}

# Example
n <- as.integer(readline("Enter a number: "))
cat(n, "is", checkEvenOdd(n), "\n")


# 4. Sum of Even Numbers up to N

sumEvenNumbers <- function(n) {
  sum <- 0
  for (i in 1:n) {
    if (i %% 2 == 0) {
      sum <- sum + i
    }
  }
  return(sum)
}

# Example
num <- as.integer(readline("Enter the limit: "))
cat("Sum of even numbers up to", num, "is", sumEvenNumbers(num), "\n")


# 5. Print Fibonacci Series up to N Terms

fibonacciSeries <- function(n) {
  if (n <= 0) {
    return("Enter a positive integer")
  }
  a <- 0
  b <- 1
  cat("Fibonacci Series:", a, b)
  for (i in 3:n) {
    c <- a + b
    cat(" ",c)
    a <- b
    b <- c
  }
  cat("\n")
}

# Example
num <- as.integer(readline("Enter number of terms: "))
fibonacciSeries(num)

