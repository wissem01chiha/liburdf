from pyurdf import pyurdf_parser

def main():
    parser = pyurdf_parser.URDFParser()
    urdf_file = "spot.urdf"
    parser.parse(urdf_file)
    model = parser.get()
    print(model.getName())
    print(model.__str__())

if __name__ == "__main__":
    main()