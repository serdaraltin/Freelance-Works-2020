using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using entities.Concrete;
namespace Bll.Abstract
{
    //öğrenci interfacesinin tanımlanması
    public interface IOgrencilerBll
    {
        List<ogrenciler> getAll();
        ogrenciler getOneById(int id);
        void Update(ogrenciler ogrenciler);
        void Add(ogrenciler ogrenciler);
        void Delete(ogrenciler ogrenciler);
    }
}
