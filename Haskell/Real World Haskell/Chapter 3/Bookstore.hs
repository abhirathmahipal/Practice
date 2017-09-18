data BookInfo = Book Int String [String]
                deriving (Show)

type CardHolder = String
type CardNumber = String
type Address = [String]
type CustomerID = Int

data BillingInfo = CreditCard CardNumber CardHolder Address
                 | CashOnDelivery
                 | Invoice CustomerID
                 deriving (Show)

-- Destruction (not OOPS, just means looking inside)
bookId (Book id title authors) = id
bookTitle (Book id title authors) = title
bookAuthors (Book id title authors) = authors

data Customer = Customer {
    customerID :: CustomerID
  , customerName :: String
  , customerAddress :: Address
} deriving (Show)

customer1 = Customer {
    customerID = 1234234
  , customerAddress = ["afsdafasdf", "fadsf", "dsffa"]
  , customerName = "Jane Q Citizen"
}
