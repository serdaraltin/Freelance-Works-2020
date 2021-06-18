using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using entities.Concrete;
namespace Bll.Abstract
{
    public interface IYazarlarBll
    {
        List<yazarlar> getAll();
        yazarlar getOneById(int id);
        void Update(yazarlar yazarlar);
        void Add(yazarlar yazarlar);
        void Delete(yazarlar yazarlar);
    }
}
